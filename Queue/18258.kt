import java.util.*

fun main() = with(System.out.bufferedWriter()) {
    val br = System.`in`.bufferedReader()
    val n = br.readLine().toInt()
    val sb = StringBuilder()
    val queue: Queue<Int> = LinkedList<Int>()
    for (i in 0 until n) {
        val str = br.readLine().split(" ")
        when (str[0]) {
            "push" -> {
                queue.offer(str[1].toInt())
            }
            "pop" -> {
                if(queue.isNotEmpty()){
                    sb.append(queue.poll()).append('\n')
                } else {
                    sb.append(-1).append('\n')
                }
            }
            "size" -> {
                sb.append(queue.size).append('\n')
            }
            "empty" -> {
                if(queue.isNotEmpty()){
                    sb.append(0).append('\n')
                } else {
                    sb.append(1).append('\n')
                }
            }
            "front" -> {
                if(queue.isNotEmpty()){
                    sb.append(queue.peek()).append('\n')
                } else {
                    sb.append(-1).append('\n')
                }
            }
            "back" -> {
                if(queue.isNotEmpty()){
                    sb.append(queue.last()).append('\n')
                } else {
                    sb.append(-1).append('\n')
                }
            }
        }
    }
    println(sb.toString())
}
