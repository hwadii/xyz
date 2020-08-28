require_relative 'lib/lib.rb'
require 'pathname'

cwd = Pathname.getwd
mocks = cwd.join('mocks')
rel_target = Pathname.new('./lib/lib.js')
rel_source = Pathname.new('./bin/main.js')
target = mocks + rel_target
source = mocks + rel_source

ri = RelativeImport.new(source: rel_source, target: rel_target)
p ri.common_parent
