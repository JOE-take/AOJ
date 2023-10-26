
class Node
  attr_accessor :value, :parent, :left, :right
  def initialize(value: nil, parent: nil, left: nil, right: nil)
    @value = value
    @parent = parent
    @left = left
    @right = right
  end
end

class BinTree
  attr_accessor :root

  def initialize(root: nil)
    @root = root
  end

  def add(node)
    if self.root.nil?
      self.root = node
      return
    end

    ctr = self.root
    parent = nil
    while !ctr.nil?
      parent = ctr
      if node.value > ctr.value
        ctr = ctr.right
      else
        ctr = ctr.left
      end
    end
    node.parent = parent
    node.value > parent.value ? parent.right = node : parent.left = node
  end

  def printTree
    inorder(self.root)
    puts("")
    preorder(self.root)
    puts("")
  end

  def findKey(key)
    if findRec(key, self.root)
      "yes"
    else
      "no"
    end
  end

end

def findRec(key, node)
  return false if node.nil?
  if node.value == key
    return true
  elsif node.value > key
    return findRec(key, node.left)
  else
    return findRec(key, node.right)
  end
end

def preorder(node)
  return if node.nil?
  print " #{node.value}"
  preorder(node.left)
  preorder(node.right)
end

def inorder(node)
  return if node.nil?
  inorder(node.left)
  print " #{node.value}"
  inorder(node.right)
end

tree = BinTree.new
n = gets.to_i
(0...n).each do
  line = gets.split(' ')
  if line[0] == "print"
    tree.printTree
    next
  elsif line[0] == "find"
    puts tree.findKey(line[1].to_i)
    next
  end

  newNode = Node.new(value: line[1].to_i)
  tree.add(newNode)
end
