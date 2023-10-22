
class Node
  attr_accessor :id, :parent, :left, :right
  def initialize(id: nil, parent: nil, left: nil, right: nil)
    @id = id
    @parent = parent
    @left = left
    @right = right
  end
end

def rec(l, r)
  return if l >= r
  root = $preorders[$ctr]
  $ctr += 1
  m = $inorders.index(root)
  rec(l, m)
  rec(m+1, r)
  $postorders.push(root)
end

n = gets.to_i
$preorders = gets.split(' ').map(&:to_i)
$inorders = gets.split(' ').map(&:to_i)
$postorders = []
$ctr = 0

rec(0, n)

puts $postorders.join(" ")
