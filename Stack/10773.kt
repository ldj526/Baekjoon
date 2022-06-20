import java.io.BufferedReader
import java.io.InputStreamReader
import java.util.*

fun main() = with(BufferedReader(InputStreamReader(System.`in`))) {
    val k = readLine().toInt()
    val stack = Stack<Int>()
    for (i in 0 until k) {
        when (val num = readLine().toInt()) {
            0 -> {
                stack.pop()
            }
            else -> {
                stack.push(num)
            }
        }
    }
    var sum = 0
    for (i in 0 until stack.size) {
        sum += stack[i]
    }
    println(sum)
}
