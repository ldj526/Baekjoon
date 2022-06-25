import java.io.BufferedReader
import java.io.InputStreamReader
import java.util.*

fun main() {
    val br = BufferedReader(InputStreamReader(System.`in`))
    val n = br.readLine().toInt()
    val stack = Stack<Long>()
    var sum :Long = 0
    stack.push(Long.MAX_VALUE)
    repeat(n) {
        val num = br.readLine().toLong()
        while (stack.isNotEmpty() && stack.peek() <= num) {
            stack.pop()
        }
        sum += (stack.size - 1)
        stack.push(num)
    }
    println(sum)
}
