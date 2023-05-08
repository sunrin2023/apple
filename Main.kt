
fun main(args:Array<String>) {
    println("")
    print("enter num1 : ")
    var num1 : Int = readLine()!!.toInt() // 첫번째 숫자 입력
    print("enter num2 : ")
    var num2 : Int = readLine()!!.toInt() // 두번째 숫자 입력
    print("enter operator : ")
    var op : Char = readLine()!![0] // 연산자 입력

    // 코드 작성
    if (op == '+'){
        print("$num1 + $num2 = ${num1 + num2}")
    }else if (op == '-') {
        print("$num1 - $num2 = ${num1 - num2}")
    }else if (op == '*') {
        print("$num1 * $num2 = ${num1 * num2}")
    }else if (op == '/') {
        print("$num1 / $num2 = ${num1 / num2}")
    }else if (op == '%') {
        print("$num1 % $num2 = ${num1 % num2}")
    }
}