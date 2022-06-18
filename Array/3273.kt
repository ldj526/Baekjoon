import java.io.BufferedReader
import java.io.InputStreamReader

fun main() = with(BufferedReader(InputStreamReader(System.`in`))) {
    val n = readLine().toInt()
    val arr = readLine().split(" ").map { it.toInt() }.toIntArray()
    arr.sort()
    val x = readLine().toInt()
    var cnt = 0
    var start = 0
    var end = n - 1
    while (start < end) {
        var sum = arr[start] + arr[end]
        if (sum == x) {
            cnt++
        }
        if (sum <= x) {
            start++
        } else {
            end--
        }
    }
    println(cnt)
}
