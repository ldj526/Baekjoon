// https://www.acmicpc.net/problem/10808

import java.io.BufferedReader
import java.io.InputStreamReader

fun main() = with(BufferedReader(InputStreamReader(System.`in`))) {
    val s = readLine()
    val arr = IntArray(26)
    for (i in s) {
        arr[i -'a']++
    }
    for (i in arr){
        print("$i ")
    }
}
