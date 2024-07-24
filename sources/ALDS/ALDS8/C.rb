
class Node
  attr_accessor :value, :parent, :left, :right
  def initialize(value: nil, parent: nil, left: nil, right: nil)
    @value = value
    @parent = parent
    @left = left
    @right = right
  end
  def isRight?
    if self.parent.right == self
      return true
    else
      return false
    end
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
    return findRec(key, self.root)
  end

  def delete(key)
    node = self.findKey(key)
    if node.nil?
      return

    # 子なしの場合
    elsif node.left.nil? && node.right.nil?
      if node.isRight?
        node.parent.right = nil
      else
        node.parent.left = nil
      end

    # 子が2つの場合
    elsif !node.left.nil? && !node.right.nil?
      successor = findMin(node.right)
      value = successor.value
      delete(successor.value)
      node.value = value

    # 子が1つの場合
    else
      if node.right.nil?
        newChildNode = node.left
      else
        newChildNode = node.right
      end

      newChildNode.parent = node.parent
      if node.isRight?
        node.parent.right = newChildNode
      else
        node.parent.left = newChildNode
      end
    end
  end
end

def findMin(node)
  current = node
  while !current.left.nil?
    current = current.left
  end
  current
end

def findRec(key, node)
    return nil if node.nil?
    if node.value == key
      return node
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
lines = []
n = gets.to_i
(0...n).each do
  lines << gets.split(' ')
end
lines.each do |line|
  if line[0] == "print"
    tree.printTree
    next
  elsif line[0] == "find"
    node = tree.findKey(line[1].to_i)
    node.nil? ? puts("no") : puts("yes")
    next
  elsif line[0] == "delete"
    tree.delete(line[1].to_i)
  elsif line[0] == "insert"
    newNode = Node.new(value: line[1].to_i)
    tree.add(newNode)
  end
end
