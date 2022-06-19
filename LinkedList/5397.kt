import java.io.BufferedReader
import java.io.InputStreamReader
import java.util.*

fun main() = with(BufferedReader(InputStreamReader(System.`in`))) {
    val a = readLine().toInt()
    for (i in 0 until a) {
        val l = readLine()
        val list = LinkedList<Char>()
        var cursor = 0
        for (element in l) {
            when (element) {
                '<' -> {
                    if (cursor != 0) {
                        cursor--
                    }
                }
                '>' -> {
                    if (cursor != list.size) {
                        cursor++
                    }
                }
                '-' -> {
                    if (cursor != 0 && list.isNotEmpty()) {
                        list.removeAt(--cursor)
                    }
                }
                else -> {
                    list.add(cursor++, element)
                }
            }
        }
        println(list.toCharArray())
    }
}
