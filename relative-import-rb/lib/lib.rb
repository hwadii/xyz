class Pathname
  def depth
    each_filename.first == '.' ? each_filename.count - 2 : each_filename.count - 1
  end
end

class RelativeImport
  attr_accessor :source, :target

  def initialize(source: nil, target: nil)
    return if source.nil? || target.nil?
    @source = source
    @target = target
    @common_parent_index = @source.each_filename.find_index(common_parent)
  end

  def common_parent
    inter = @source.each_filename.to_a & @target.each_filename.to_a
    inter&.last
  end

  # dots => depth of source - common_ancestor.index - 1
  # we add -1 because compute_dots == 1 means same dir
  def compute_dots
    @source.depth - @common_parent_index
  end

  def compute_rest
    @target.each_filename.to_a[(@common_parent_index + 1)..].join('/')
  end

  def build_relative
    prelude = ''
    compute_dots.times { prelude << '../' }
    prelude = './' if prelude.empty?
    Pathname.new(prelude + compute_rest)
  end
end
