import java.io.BufferedReader
import java.io.InputStreamReader

fun main() = with(BufferedReader(InputStreamReader(System.`in`))) {
    val a = readLine().toInt()
    val b = readLine().toInt()
    val c = readLine().toInt()
    var result = (a * b * c).toString()
    val arr = IntArray(10)
    for (element in result) {
        arr[element - '0']++
    }
    for(i in 0..9){
        println(arr[i])
    }
}
