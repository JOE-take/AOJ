
class Node
  attr_accessor :id, :parent, :left, :right
  def initialize(id: nil, parent: nil, left: nil, right: nil)
    @id = id
    @parent = parent
    @left = left
    @right = right
  end
end

def preorder(node)
  return if node.nil?
  print " #{node.id}"
  preorder(node.left)
  preorder(node.right)
end

def inorder(node)
  return if node.nil?
  inorder(node.left)
  print " #{node.id}"
  inorder(node.right)
end

def postorder(node)
  return if node.nil?
  postorder(node.left)
  postorder(node.right)
  print " #{node.id}"
end

n = gets.to_i
t = []
(0...n).each do |i|
  t.push(Node.new(id: i))
end

(0...n).each do
  line = gets.split(' ')
  id = line[0].to_i
  leftID = line[1].to_i
  rightID = line[2].to_i

  if leftID != -1
    t[leftID].parent = t[id]
    t[id].left = t[leftID]
  end
  if rightID != -1
    t[rightID].parent = t[id]
    t[id].right = t[rightID]
  end
end

root = nil
(0...n).each do |i|
  if t[i].parent.nil?
    root = t[i]
    break
  end
end

puts "Preorder"
preorder(root)
puts ""

puts "Inorder"
inorder(root)
puts ""

puts "Postorder"
postorder(root)
puts ""
