require 'pathname'
require_relative '../lib/lib'
require 'test/unit'

class TestRelativeImport < Test::Unit::TestCase
  def test_common_parent
    ri = RelativeImport.new(source: Pathname.new('./bin/main.js'), target: Pathname.new('./lib/lib.js'))
    assert_equal(ri.common_parent, '.')
    ri.source = Pathname.new('./lib/math/math.js')
    assert_equal(ri.common_parent, 'lib')
  end

  def test_build_relative_simple
    ri = RelativeImport.new(source: Pathname.new('./lib/math/math.js'), target: Pathname.new('./lib/math/lib.js'))
    p ri.compute_dots
    assert_equal(ri.build_relative, Pathname.new('./lib.js'))
  end

  def test_build_relative_deep
    ri = RelativeImport.new(source: Pathname.new('./lib/math/math.js'), target: Pathname.new('./lib/lib.js'))
    assert_equal(ri.build_relative, Pathname.new('../../lib.js'))
  end

  def test_compute_rest
    ri = RelativeImport.new(source: Pathname.new('./lib/math/math.js'), target: Pathname.new('./lib/lib.js'))
    assert_equal(ri.compute_rest, 'lib.js')
  end
end
