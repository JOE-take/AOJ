
def partition(a, p, r)
  x = a[r]
  i = p-1
  (p...r).each do |j|
    if a[j] <= x
      i = i + 1
      a[i], a[j] = a[j], a[i]
    end
  end
  a[i+1], a[r] = a[r], a[i+1]
  return a, i+1
end

n = gets.to_i
a = gets.split(' ').map(&:to_i)
p = 0
r = a.length - 1

a, r = partition(a, p, r)

(0...a.length-1).each do |i|
  if i == r
    print "[#{a[i]}] "
  else
    print "#{a[i]} "
  end
end

l = a[a.length-1]
if a.length-1 == r
  print "[#{l}]"
else
  print "#{l}"
end

puts
