
class Node
  attr_accessor :id, :parent, :left, :right
  def initialize(id: nil, parent: nil, left: nil, right:nil)
    @id = id
    @parent = parent
    @left = left
    @right = right
  end

  def childIds
    childIds = []
    ctr = self.left
    while ctr != nil do
      childIds.push(ctr.id)
      ctr = ctr.right
    end
    return childIds.to_s
  end

  def depth
    num = 0
    ctr = self
    while ctr.parent != nil && ctr.parent != -1
      num += 1
      ctr = ctr.parent
    end
    return num
  end

  def kind
    if self.parent == -1
      "root"
    elsif self.left == nil
      "leaf"
    else
      "internal node"
    end
  end

end

n = gets().to_i
tree = []
(0...n).each do |i|
  tree.push(Node.new(id: i))
end

(0...n).each do
  line = gets.split(' ')
  id = line[0].to_i
  k = line[1].to_i
  
  tree[id].parent = -1 if tree[id].parent.nil? 

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
  if tree[i].parent == -1
    puts "node #{i}: parent = #{tree[i].parent}, depth = #{tree[i].depth}, #{tree[i].kind}, #{tree[i].childIds}"
  else
    puts "node #{i}: parent = #{tree[i].parent.id}, depth = #{tree[i].depth}, #{tree[i].kind}, #{tree[i].childIds}"
  end
end
