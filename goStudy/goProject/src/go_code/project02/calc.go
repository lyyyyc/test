package main

import "fmt"

func calc (base int) (func (int) int, func (int) int){
  fmt.Printf("%v\n", &base)
  add := func (i int) int{
    fmt.Printf("%v\n", &base)
    base += i
    return base
  }
  sub := func (i int) int{
    fmt.Printf("%v\n", &base)
    base -= i
    return base
  }
  return add, sub
}

func main(){
  t1, t2 := calc(100)
  fmt.Println(t1(1), t2(2))//执行顺序：t1，t2，println
  fmt.Println(t1(3), t2(4)) 
  fmt.Println(t1(5), t2(6)) 
  fmt.Println(t1(7), t2(8)) 
  fmt.Println(t1(9), t2(10)) 
}
