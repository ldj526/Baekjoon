package practice

import java.util.*

fun main() = with(System.out.bufferedWriter()) {
    val br = System.`in`.bufferedReader()
    val n = br.readLine().toInt()
    val sb = StringBuilder()
    val deq: Deque<Int> = LinkedList<Int>()
    for (i in 0 until n) {
        val input = br.readLine().split(" ")
        when (input[0]) {
            "push_front" -> {
                deq.offerFirst(input[1].toInt())
            }
            "push_back" -> {
                deq.offerLast(input[1].toInt())
            }
            "pop_front" -> {
                if (deq.isNotEmpty()) {
                    sb.append(deq.pollFirst()).append('\n')
                } else {
                    sb.append(-1).append('\n')
                }
            }
            "pop_back" -> {
                if (deq.isNotEmpty()) {
                    sb.append(deq.pollLast()).append('\n')
                } else {
                    sb.append(-1).append('\n')
                }
            }
            "size" -> {
                sb.append(deq.size).append('\n')
            }
            "empty" -> {
                if (deq.isNotEmpty()) {
                    sb.append(0).append('\n')
                } else {
                    sb.append(1).append('\n')
                }
            }
            "front" -> {
                if (deq.isNotEmpty()) {
                    sb.append(deq.peekFirst()).append('\n')
                } else {
                    sb.append(-1).append('\n')
                }
            }
            "back" -> {
                if (deq.isNotEmpty()) {
                    sb.append(deq.peekLast()).append('\n')
                } else {
                    sb.append(-1).append('\n')
                }
            }
        }
    }
    println(sb.toString())
}
