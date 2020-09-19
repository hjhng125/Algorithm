package com.company;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main {

    static int[] dx = {1, -1, 0, 0};
    static int[] dy = {0, 0, 1, -1};
    static int tc, m, n, k, bugs;
    static Queue<Node> q;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        tc = Integer.parseInt(br.readLine());

        while (--tc >= 0) {
            bugs = 0;
            StringTokenizer st = new StringTokenizer(br.readLine(), " ");
            while (st.hasMoreTokens()) {
                m = Integer.parseInt(st.nextToken()); // 가로
                n = Integer.parseInt(st.nextToken()); // 세로
                k = Integer.parseInt(st.nextToken()); // 배추수
            }
            int[][] map = new int[n + 1][m + 1];
            q = new LinkedList<>();
            for (int i = 0; i < k; ++i) {
                st = new StringTokenizer(br.readLine(), " ");
                int x = Integer.parseInt(st.nextToken()); // 가로
                int y = Integer.parseInt(st.nextToken()); // 세로
                map[y][x] = 1;
            }

            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < m; ++j) {
                    if (map[i][j] == 0) {
                        continue;
                    }
                    bfs(i, j, map);
                }
            }
            System.out.println(bugs);
        }
        br.close();
    }

    public static void bfs(int i, int j, int[][] map) {

        q.add(new Node(i, j));
        map[i][j] = 0;
        bugs++;
        while (!q.isEmpty()) {
            Node cur = q.poll();
            int cRow = cur.row;
            int cCol = cur.col;

            for (int dir = 0; dir < 4; ++dir) {
                int nRow = cRow + dy[dir];
                int nCol = cCol + dx[dir];
                if (nRow >= n || nRow < 0 || nCol >= m || nCol < 0 || map[nRow][nCol] == 0) continue;
                q.add(new Node(nRow, nCol));
                map[nRow][nCol] = 0;
            }
        }
    }
}

class Node {
    int row, col;

    Node(int row, int col) {
        this.row = row;
        this.col = col;
    }
}