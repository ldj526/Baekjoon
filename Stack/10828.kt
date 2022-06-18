import java.io.BufferedReader
import java.io.InputStreamReader
import java.util.*

fun main() = with(BufferedReader(InputStreamReader(System.`in`))) {
    val n = readLine().toInt()
    val st = Stack<Int>()
    for (i in 0 until n) {
        var str = readLine().split(" ")
        when (str[0]) {
            "push" -> {
                st.push(str[1].toInt())
            }
            "pop" -> {
                if (st.isNotEmpty()) {
                    println(st.pop())
                } else {
                    println(-1)
                }
            }
            "size" -> {
                println(st.size)
            }
            "empty" -> {
                if (st.isNotEmpty()) {
                    println(0)
                } else {
                    println(1)
                }
            }
            else -> {
                if (st.isNotEmpty()) {
                    println(st.peek())
                } else {
                    println(-1)
                }
            }
        }
    }
}
