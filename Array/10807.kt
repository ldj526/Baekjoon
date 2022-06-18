import java.io.BufferedReader
import java.io.InputStreamReader

fun main() = with(BufferedReader(InputStreamReader(System.`in`))) {
    val n = readLine().toInt()
    val arr = readLine().split(" ").map { it.toInt() }.toIntArray()
    val arr2 = IntArray(202)
    val v = readLine().toInt()
    for (i in 0 until n) {
        arr2[arr[i] + 100]++
    }
    println(arr2[v + 100])
}
