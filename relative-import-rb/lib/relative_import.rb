class RelativeImport
  def initialize(source: nil, target: nil)
    raise ArgumentError.new("Source and target files should be defined. #{source.inspect} and #{target.inspect} given") if source.nil? || target.nil?
    @source, = source.cleanpath.split
    @target, @target_basename = target.cleanpath.split
    @source = @source.each_filename.to_a
    @target = @target.each_filename.to_a
  end

  def build_relative
    relpath = compute_dots + @target
    if relpath.empty?
      @target_basename
    else
      Pathname.new(relpath.join('/')) + @target_basename
    end
  end

  private

  def compute_dots
    while !@source.empty? && !@target.empty? && @source.first == @target.first
      @source.shift
      @target.shift
    end
    @source.fill('..')
  end
end
