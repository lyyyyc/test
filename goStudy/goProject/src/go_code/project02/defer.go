package main

import "fmt"

func main(){
  /*x, y := 1, 2
  defer func (a int){
    fmt.Println("defer x, y = ", x, y)
  }(x)
  x += 100
  y += 200
  fmt.Println("x, y = ", x, y)*/

  for i := 0; i < 3; i++{
    defer func(){
      fmt.Println(i)
    }()
    fmt.Print(i)
    if i == 2{
      fmt.Print("\n")
    }
  }
}
