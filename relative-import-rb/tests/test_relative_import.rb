require 'pathname'
require_relative '../lib/lib'
require 'test/unit'

class TestRelativeImport < Test::Unit::TestCase
  def test_build_relative_simple
    ri = RelativeImport.new(source: Pathname.new('./lib/math/math.js'), target: Pathname.new('./lib/math/lib.js'))
    assert_equal(ri.build_relative, Pathname.new('lib.js'))
  end

  def test_build_relative_simple_2
    ri = RelativeImport.new(source: Pathname.new('./main.js'), target: Pathname.new('./lib.js'))
    assert_equal(ri.build_relative, Pathname.new('lib.js'))
  end

  def test_build_relative_complex
    ri = RelativeImport.new(source: Pathname.new('./lib/main/main/main/main.js'), target: Pathname.new('./util.js'))
    assert_equal(ri.build_relative, Pathname.new('../../../../util.js'))
  end

  def test_build_relative_complex_2
    ri = RelativeImport.new(source: Pathname.new('./lib/main/main/main/main.js'), target: Pathname.new('./lib/main/main/math/math.js'))
    assert_equal(ri.build_relative, Pathname.new('../math/math.js'))
  end

  def test_build_relative_deep
    ri = RelativeImport.new(source: Pathname.new('./lib/math/math.js'), target: Pathname.new('./lib/lib.js'))
    assert_equal(ri.build_relative, Pathname.new('../lib.js'))
  end

  def test_compute_dots
    ri = RelativeImport.new(source: Pathname.new('./lib/math/math.js'), target: Pathname.new('./lib/lib.js'))
    assert_equal(ri.compute_dots, ['..'])
  end
end
