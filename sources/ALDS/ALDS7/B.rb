def findHeightRec(num, node)
  return num if node.nil?
    
  num += 1
  num1 = findHeightRec(num, node.left)
  num2 = findHeightRec(num, node.right)
  return [num1, num2].max
end

class Node
  attr_accessor :id, :parent, :left, :right
  def initialize(id: nil, parent: nil, left: nil, right: nil)
    @id = id
    @parent = parent
    @left = left
    @right = right
  end
  
  def sibling
    if self.parent.nil?
      return -1
    end
    
    if parent.left && parent.left == self
      if parent.right.nil?
        return -1
      else
        return parent.right.id
      end 
    else
      if parent.left.nil?
        return -1
      else
        return parent.left.id
      end
    end

  end
  
  def degree
    num = 0
    num += 1 if !self.left.nil?
    num += 1 if !self.right.nil?
    return num
  end
  
  def height 
    return  findHeightRec(-1, self)
  end
  
  def depth
    num = 0
    ctr = self
    while !ctr.parent.nil?
      num += 1
      ctr = ctr.parent
    end
    return num
  end

  def kind
    if self.parent == nil
      "root"
    elsif !self.left && !self.right
      "leaf"
    else
      "internal node"
    end
  end
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

(0...n).each do |i|
  puts "node #{i}: parent = #{t[i].parent.nil? ? -1 : t[i].parent.id}, sibling = #{t[i].sibling}, degree = #{t[i].degree}, depth = #{t[i].depth}, height = #{t[i].height}, #{t[i].kind}"
end
