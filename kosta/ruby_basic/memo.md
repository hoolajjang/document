Ruby 기초
===

# 기본사용

## 실행
- irb 사용
- ruby hello.rb 로 파일 실행
- irb 내에서 load "hello.rb"로 파일 로드

## 출력
```rb
#주석은 이걸로
#puts "한줄출력"
puts "Hello world"
puts "야야야야야야"
print "그냥출력"
print "aaaa"
puts ('asdjflajsldfjasldf')
```
## 변수대입
```rb
a,b = 1,2
puts a
puts b
puts

a,b = [10, 20, 30]
puts a
puts b
puts

c,d,e = [4, 5]
puts c
puts d
puts e
```

## 연산자
```rb
puts "ruby language".reverse
puts "ruby language".length
puts 22.next
puts 22.pred

str1 = "hello world"
str2 = str1.reverse
num = 5
str3 = str1*num

puts str1
puts str2
puts str3
```

## 자료형
- 상수는 대문자로 작성할 뿐 변경 가능하다.(경고는 뜸)
- 자료형에 매우 관대함
- 숫자는 모두 Number
- 문자는 모두 String
- 서로 다른 문자 이어서 출력할때는 꼭 쌍따움표를 써야함
```rb
var1 = 10
var2 = 'ruby language'

puts var1
puts var2

puts "#{var1} and #{var2}"
```
- 문자는 +연산자로 이을 수 있음
```rb
a = "Hi,"
b = "KKH"
c = a + " " + b
puts a,b,c
```

## 조건문
- if ~ else
- if ~ elseif ~ else
```rb
puts "game"
print "where are you going? : "
direction = gets.chomp.encode("utf-8")

puts "I going to #{direction}."
```
- unless는 부정문
- 삼항연산자
```rb
x=5
puts x.nil? ? "aaa" : "bbb"
```
- if ~ then
- case ~ when ~ else
```rb
number = 7
case number
when 0
  puts "0"
when 1..10
  puts "1~10"
else
  puts "Default!!!"
end
```

## 반복문
- do ~ end
```rb
list = [1,2,3,4,5]
list.each do |d|
  puts d
end
```
- 블럭 사용
```rb
(1..100).each {|x| puts x}
sum = 0
(1..100).each {|x| sum += x}
puts sum
```
- for in
```rb
arr = [1,2,3,4,5]
for x in arr
  if x.even?
    puts "Even!!!"
  else
    puts "Ode!!!"
  end
end
```
- while 조건 do 실행문 end
```rb
x = 0
while x<10 do
  puts x
  x += 1
  
  break if x == 5
end
```
- until 조건 do 실행문 end
- times, upto, downto, step
```rb
3.times do
  puts "hi!!!"
end
puts

sum = 0
1.upto(10) do |x|
  sum += x
end
puts sum

10.downto(1) do |x|
  print x, " "
end
puts

0.step(10,2) do |x|
  print x, " "
end
```
- next는 continue와 같고 next if로 조건을 둘 수 있음

## 배열
- 배열에 사이즈가 없음
- index 0부터 시작
- 음수 index 사용하면 오른쪽부터 -1로 접근 가능
- 유효하지 않은 index 접근은 nil
- 최대 지정 인덱스 만큼 사이즈가 들어나고 그 사이는 nil로 체워짐
- 인덱스가 두개인 경우 시작점과 갯수를 의미
```rb
x = ["aaa", "bbb", "ccc"]
puts x[0]
puts x[100]
puts x[-1]

x[5] = "zzz"
puts x[5]
puts x[4]
puts x[2,2]
```
- 배열 안에 배열 넣을 수 있음
```rb
arr=[1,3,5,7,9]
print arr[1..3];puts
print arr[-2..-1];puts
arr[1]="bat"
print arr;puts
arr[3] = [2,4,6]
print arr;puts
arr[2,2] = 100
print arr;puts
```
- push, pop을 가지고 배열을 스택으로 이용 가능
```rb
arr = []
arr.push "red"
puts arr
arr.push "green"
arr.push "blue"
print arr;puts
puts arr.pop
```
- shift, unshift
```rb
arr = []
arr.push "red"
arr.push "green"
arr.push "blue"
puts arr

puts arr.pop
print arr;puts

puts arr.shift
print arr;puts
arr.unshift("yellow")
print arr;
```
- first, last
```rb
arr = [1,2,3,4,5,6,7,8,9]
print arr;puts
print arr.first(4);puts
print arr;puts
print arr.last(4);puts
print arr;puts
print arr.pop(4);puts
print arr;puts
```

## 심볼
- 변수만 저장 가능하고 값은 저장 할 수 없음
```rb
str1 = "aaa"
str2 = "aaa"
str3 = "aaa"

st1 = :aaa
st2 = :aaa
st3 = :aaa
#st4 = "bbb" 안됨.

puts str1.object_id
puts str2.object_id
puts str3.object_id

puts st1.object_id
puts st2.object_id
puts st3.object_id
```

## 해시
```rb
hash1 = {}
hash2 = Hash.new
hash3 = {1=>10, 2=>"aaa", 3=>"bbb", "xxx"=>"XXX", "zzz"=>"ZZZ"}
hash4 = {:John=>18, :Eric=>25}
hash5 = {John:18, Eric:25}

puts hash3
puts hash3.keys
puts hash3.values
puts hash4
puts hash5

puts hash3["xxx"]
puts hash4[:John]
puts hash3.length
puts hash3.empty?
puts hash3.has_key?("zzz")
puts hash3.has_value?("aaa")


hash3.each do |name,age|
  print name, "\t", age, "\n"
end

hash3.each_key do |name|
  puts name
end

hash3.each_value do |age|
  puts age
end
```


## 연습
- 숫자를 입력받고 배열에 저장하면서 q를 입력하면 짝수, 홀수 각각 합을 출력하고 종료
```rb
direction = ""
arr = []
evenSum=0, oddSum=0

until direction=="q" do
  print "숫자를 입력하면 짝홀수 각각 합을 구해드립니다. : "
  direction = gets.chomp
  num = direction.to_i
  arr.push num
  
  if num.even?
    evenSum += num
  else
    oddSum += num
  end  
end
puts arr
print "EvenSum = "
puts evenSum
print "oddSum = "
puts oddSum
```
- 배열의 역 명을 보여주고 선택하게 하고 q로 종료
```rb
#station = ["서울", "용산", "대전", "대구", "부산"]
station = ["aaa", "bbb", "ccc", "ddd", "eee"]
direction = ""
until direction=="q" do
  print "목적지를 입력하세요. "
  direction = gets.chomp.encode("utf-8")
  puts "목적지는 #{direction}입니다."
  if station.include? direction
    print "경로는 - "
    station.each do |st|
      print st, " "
      break if st == direction
    end
    puts
  else
    puts "그런역은 없습니다."
  end
end
```
- each do 이용해서 menu해시에서 각 품목의 가격을 출력.
```rb
menu = {
  egg:200,
  jam:100,
  juice:300,
  milk:200,
}

puts menu
menu["water"] = 150
puts menu
puts menu["water"]
menu[:gimbab] = 250
puts menu
puts menu[:gimbab]
menu.delete("water")
puts menu
menu.delete(:gimbab)
puts menu

menu.each do |key, value|
  puts "#{key}의 가격은 #{value}원입니다."
end
```
- 메뉴와 가격을 입력받아 메뉴를 추가하는 프로그램 작성
```rb
menus = {
  egg:200,
  jam:100,
  juice:300,
  milk:200,
}
direction = ""
until direction=="q" do
  print "메뉴 - "
  menu = gets.chomp.encode("utf-8")
  if menu=="q"
    direction = menu
    break
  end
  
  print "가격 - "
  price = gets.chomp.encode("utf-8")
  
  if price=="q"
    break
  end
  
  menus[menu.to_sym] = price
end

puts menus
```











