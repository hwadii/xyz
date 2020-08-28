class Pathname
  def depth
    each_filename.count - 1
  end
end

class RelativeImport
  attr_accessor :source, :target, :root

  def initialize(source: nil, target: nil)
    return if source.nil? || target.nil?
    @source = source
    @target = target
    @root = Pathname.getwd.join('mocks')
  end

  def common_parent
    deepest = @source.depth >= @target.depth ? @source : @target
  end
end
