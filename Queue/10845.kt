import java.util.*

val queue: Queue<Int> = LinkedList<Int>()
fun main() = with(System.out.bufferedWriter()) {
    val br = System.`in`.bufferedReader()
    val n = br.readLine().toInt()

    for (i in 0 until n) {
        val str = br.readLine().split(" ")
        when (str[0]) {
            "push" -> {
                push(str[1].toInt())
            }
            "pop" -> {
                pop()
            }
            "size" -> {
                size()
            }
            "empty" -> {
                empty()
            }
            "front" -> {
                front()
            }
            "back" -> {
                back()
            }
        }
    }
}

fun push(x: Int) {
    queue.offer(x)
}

fun pop() {
    if (queue.isNotEmpty()) {
        println(queue.poll())
    } else {
        println(-1)
    }
}

fun size() {
    println(queue.size)
}

fun empty() {
    if (queue.isNotEmpty()) {
        println(0)
    } else {
        println(1)
    }
}

fun front() {
    if (queue.isNotEmpty()) {
        println(queue.peek())
    } else {
        println(-1)
    }
}

fun back() {
    if (queue.isNotEmpty()) {
        println(queue.last())
    } else {
        println(-1)
    }
}
