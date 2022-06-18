import java.io.BufferedReader
import java.io.InputStreamReader

fun main() = with(BufferedReader(InputStreamReader(System.`in`))) {
    val num = readLine()
    val number = IntArray(10)
    val number69 = IntArray(2)
    for (i in num) {
        when (i) {
            '6' -> {
                number69[0]++
            }
            '9' -> {
                number69[1]++
            }
            else -> {
                number[i - '0']++
            }
        }
    }
    var sum = number69[0] + number69[1]
    var a = 0
    if (sum % 2 == 0) {
        a = sum / 2
    } else {
        a = sum / 2 + 1
    }
    number.sort()
    if (a > number[9]) {
        println(a)
    } else {
        println(number[9])
    }
}
