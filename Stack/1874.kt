import java.io.BufferedReader
import java.io.InputStreamReader
import java.util.*

fun main() = with(BufferedReader(InputStreamReader(System.`in`))) {
    val k = readLine().toInt()
    val st = Stack<Int>()
    val list = ArrayList<Char>()
    var cnt = 1
    for (i in 0 until k) {
        val num = readLine().toInt()
        while (cnt <= num) {
            st.push(cnt)
            list.add('+')
            cnt++
        }
        if (num == st.peek()){
            st.pop()
            list.add('-')
        } else {
            println("NO")
            return
        }
    }
    for (i in list) {
        println(i)
    }
}
