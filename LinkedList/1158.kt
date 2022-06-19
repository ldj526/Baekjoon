import java.io.BufferedReader
import java.io.InputStreamReader
import java.util.*

fun main() {
    val br = BufferedReader(InputStreamReader(System.`in`))
    val st = StringTokenizer(br.readLine())
    val n = st.nextToken().toInt()
    val k = st.nextToken().toInt()
    val list = LinkedList<Int>()
    for (i in 1..n) {
        list.add(i)
    }
    print("<")
    while (list.isNotEmpty()) {
        for (i in 1..k) {
            if (i != k) {
                list.add(list.remove())
            } else if (list.size != 1) {
                print(list[0])
                print(", ")
                list.remove()
            } else {
                print(list[0])
                list.remove()
            }
        }
    }
    print(">")
}
