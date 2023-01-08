#pragma once

void BFS()
{
    queue<int> q;
    // Инициализация: есть информация про начальную вершину
    q.push(start);
    d[start] = 0;
    mark[start] = 1;
    // Главный цикл - пока есть серые вершины
    while (!q.empty())
    {
        // Берем первую из них
        int v = q.front();
        q.pop();
        // Пробегаемся по всем ее соседям
        for (int i = 0; i < (int)edges[v].size(); ++i)
        {
            // Если сосед белый
            if (mark[edges[v][i]] == 0)
            {
                // То вычисляем расстояние
                d[edges[v][i]] = d[v] + 1;
                // И он становится серым
                mark[edges[v][i]] = 1;
                q.push(edges[v][i]);
            }
        }
    }
}