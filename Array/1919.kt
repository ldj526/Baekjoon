import java.io.BufferedReader
import java.io.InputStreamReader

fun main() = with(BufferedReader(InputStreamReader(System.`in`))) {
    val a = readLine()
    val b = readLine()
    val arr1 = IntArray(26)
    val arr2 = IntArray(26)
    for (i in a.indices) {
        arr1[a[i] - 'a']++
    }
    for (i in b.indices) {
        arr2[b[i] - 'a']++
    }
    var cnt = 0
    for (i in 0 until 26) {
        if (arr1[i] < arr2[i]) {
            while (arr1[i] < arr2[i]) {
                arr2[i]--
                cnt++
            }
        } else if (arr1[i] > arr2[i]) {
            while (arr1[i] > arr2[i]) {
                arr1[i]--
                cnt++
            }
        }
    }
    println(cnt)
}
