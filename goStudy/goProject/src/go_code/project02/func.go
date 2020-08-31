package main

import "fmt"

func Add(base int) func (int) int{
  fmt.Printf("%v\n", &base)
  f := func (i int) int{
    fmt.Printf("%v\n", &base)
    base += i
    return base
  }
  return f
}

func main(){
  t1 := Add(10)
  fmt.Println(t1(1), t1(2))
  t2 := Add(100)
  fmt.Println(t2(1), t2(2))
}
