import java.io.BufferedReader
import java.io.InputStreamReader
import java.util.*

fun main() {
    val br = BufferedReader(InputStreamReader(System.`in`))
    val st = StringTokenizer(br.readLine())
    val n = st.nextToken().toInt()
    val k = st.nextToken().toInt()
    val arr = IntArray(12)
    for (i in 0 until n) {
        val st1 = StringTokenizer(br.readLine())
        val s = st1.nextToken().toInt()
        val y = st1.nextToken().toInt()
        when (y) {
            1 -> {
                when (s) {
                    0 -> arr[0]++
                    1 -> arr[1]++
                }
            }
            2 -> {
                when (s) {
                    0 -> arr[2]++
                    1 -> arr[3]++
                }
            }
            3 -> {
                when (s) {
                    0 -> arr[4]++
                    1 -> arr[5]++
                }
            }
            4 -> {
                when (s) {
                    0 -> arr[6]++
                    1 -> arr[7]++
                }
            }
            5 -> {
                when (s) {
                    0 -> arr[8]++
                    1 -> arr[9]++
                }
            }
            6 -> {
                when (s) {
                    0 -> arr[10]++
                    1 -> arr[11]++
                }
            }
        }
    }
    var cnt = 0
    for (i in 0 until 12) {
        if (arr[i] % k == 0) {
            cnt += arr[i] / k
        } else {
            cnt += arr[i] / k + 1
        }
    }
    println(cnt)
}
