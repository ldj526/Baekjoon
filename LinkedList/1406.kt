import java.io.BufferedReader
import java.io.InputStreamReader
import java.util.*

fun main() = with(BufferedReader(InputStreamReader(System.`in`))) {
    val s = readLine()
    val list = LinkedList<Char>()
    for (i in s) list.add(i)
    val it = list.listIterator()
    while (it.hasNext()) {
        it.next()
    }
    val n = readLine().toInt()
    for (i in 0 until n) {
        val ch = readLine()
        when (ch[0]) {
            'L' -> {
                if (it.hasPrevious())
                    it.previous()
            }
            'D' -> {
                if (it.hasNext())
                    it.next()
            }
            'B' -> {
                if (it.hasPrevious()) {
                    it.previous()
                    it.remove()
                }
            }
            else -> {
                it.add(ch[2])
            }
        }
    }
    println(list.toCharArray())
}
