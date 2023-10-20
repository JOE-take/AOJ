
class Node
  attr_accessor :id, :parent, :left, :right
  def initialize(id: nil, parent: nil, left: nil, right:nil)
    @id = id
    @parent = parent
    @left = left
    @right = right
  end
end

n = gets().to_i
tree = []
(0...n).each do |i|
  tree.append(Node.new)
end

(0...n).each do
  line = gets.split(' ')
  id = line[0].to_i
  k = line[1].to_i
  tree[id].id = id
  
  if id == 0
    tree[id].parent = -1
  end

  l = nil
  (0...k).each do |j|
    elementId = line[j+2].to_i

    tree[elementId].parent = tree[id]
    if j == 0
      tree[id].left = tree[elementId]
    else
      l.right = tree[elementId]
    end
    l = tree[elementId]
  end
end

(0...n).each do |i|
  if tree[i].parent != -1
    puts "#{tree[i].id}, #{tree[i].parent.id}"
  else
    puts "#{tree[i].id}, #{tree[i].parent}"
  end
end