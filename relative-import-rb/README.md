# Relative import

## Description

Find the shortest path between two files in the same subtree.

## Usage

```ruby
require 'relative_import'

from = Pathname.new('./bin/main.js')
to = Pathname.new('./lib/lib.js')

RelativeImport.new(source: from, target: to).build_relative
# => #<Pathname:../lib/lib.js>
```

## Why?

Initially, I just wanted to write this small library in rust but I wasn't sure
about the implementation so I decided to write it in ruby first. I'm going to
write it in rust next.

## TODO

- [ ] Prepend `./` if the target is in the same dir.
