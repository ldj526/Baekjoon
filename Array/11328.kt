import java.io.BufferedReader
import java.io.InputStreamReader
import java.util.*

fun main() {
    val br = BufferedReader(InputStreamReader(System.`in`))
    val st = StringTokenizer(br.readLine())
    val n = st.nextToken().toInt()
    for (i in 0 until n) {
        val st1 = StringTokenizer(br.readLine())
        var a = st1.nextToken().toCharArray()
        var b = st1.nextToken().toCharArray()
        a.sort()
        b.sort()
        if (a.contentEquals(b)) {
            println("Possible")
        } else {
            println("Impossible")
        }
    }
}
