import java.util.*


fun main() = with(System.out.bufferedWriter()) {
    val br = System.`in`.bufferedReader()
    val n = br.readLine().toInt()
    val sb = StringBuilder()
    val queue: Queue<Int> = LinkedList<Int>()
    for (i in 1..n) {
        queue.offer(i)
    }
    while (queue.size != 1) {
        queue.poll()
        queue.offer(queue.first())
        queue.poll()
    }
    println(queue.peek())
}
