import java.io.BufferedReader
import java.io.InputStreamReader
import java.util.*

class Pair {
    var num: Int
    var height: Int

    constructor(num: Int, height: Int) {
        this.num = num
        this.height = height
    }
}

fun main() = with(BufferedReader(InputStreamReader(System.`in`))) {
    val n = readLine().toInt()
    val stack = Stack<Pair>()
    var cnt: Long = 0
    for (i in 0 until n) {
        val height = readLine().toInt()
        val pair: Pair = Pair(1, height)
        while (stack.isNotEmpty() && stack.peek().height <= height) {
            val pop: Pair = stack.pop()
            cnt += pop.num
            if (pop.height == height) {
                pair.num += pop.num
            }
        }
        if (stack.isNotEmpty()) {
            cnt++
        }
        stack.push(pair)
    }
    println(cnt)
}
