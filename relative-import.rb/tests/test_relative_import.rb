require 'pathname'
require_relative '../lib/lib'
require 'test/unit'
 
class TestRelativeImport < Test::Unit::TestCase
  def test_common_parent
    ri = RelativeImport.new(source: Pathname.new('./bin/main.js'), target: Pathname.new('./lib/lib.js'))
    assert_equal(ri.common_parent, ri.source)
    ri.source = Pathname.new('./main.js')
    assert_equal(ri.common_parent, ri.target)
  end
end
