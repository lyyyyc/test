package main

import(
  "fmt"
  "time"
)

func main(){
  ch := make(chan int, 1)
  for i := 0; i < 5; i++{
    go func(){
      fmt.Println(i)
      ch <- 1
    }()
    <- ch
  }
  time.Sleep(time.Second * 1)
}
