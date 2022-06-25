import java.io.BufferedReader
import java.io.InputStreamReader
import java.util.*

class Top {
    var num: Int
    var height: Int

    constructor(num: Int, height: Int) {
        this.num = num
        this.height = height
    }
}

fun main() = with(BufferedReader(InputStreamReader(System.`in`))) {
    val sb = StringBuilder()
    val n = readLine().toInt()
    val st = StringTokenizer(readLine(), " ")

    val stack = Stack<Top>()
    for (i in 1..n) {
        val height = st.nextToken().toInt()
        if (stack.isEmpty()) {
            sb.append("0 ")
            stack.push(Top(i, height))
        } else {
            while (true) {
                if (stack.isEmpty()) {
                    sb.append("0 ")
                    stack.push(Top(i, height))
                    break
                }
                var top: Top = stack.peek()
                if (top.height > height) {
                    sb.append("${top.num} ")
                    stack.push(Top(i, height))
                    break
                } else {
                    stack.pop()
                }
            }
        }
    }
    println(sb.toString())
}
