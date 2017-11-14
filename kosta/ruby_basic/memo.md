Ruby 기초
===

#기본사용

##실행
- irb 사용
- ruby hello.rb 로 파일 실행
- irb 내에서 load "hello.rb"로 파일 로드

##출력
```rb
#주석은 이걸로
#puts "한줄출력"
puts "Hello world"
puts "야야야야야야"
print "그냥출력"
print "aaaa"
puts ('asdjflajsldfjasldf')
```
##변수대입
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

##연산자
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

##자료형
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

##조건문
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

##반복문
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
