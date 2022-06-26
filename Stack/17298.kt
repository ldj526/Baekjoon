import java.io.BufferedReader
import java.io.InputStreamReader
import java.util.*

fun main() = with(BufferedReader(InputStreamReader(System.`in`))) {
    val sb = StringBuilder()
    val n = readLine().toInt()
    val stack = Stack<Int>()
    val arr = IntArray(n)
    val st = StringTokenizer(readLine(), " ")
    for (i in 0 until n) {
        arr[i] = st.nextToken().toInt()
    }
    for (i in 0 until n) {
        while (stack.isNotEmpty() && arr[stack.peek()] < arr[i]) {
            arr[stack.pop()] = arr[i]
        }
        stack.push(i)
    }
    while (stack.isNotEmpty()) {
        arr[stack.pop()] = -1
    }
    for (i in 0 until n) {
        sb.append(arr[i]).append(' ')
    }
    println(sb.toString())
}
