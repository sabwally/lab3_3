#pragma once

void BFS()
{
    queue<int> q;
    // �������������: ���� ���������� ��� ��������� �������
    q.push(start);
    d[start] = 0;
    mark[start] = 1;
    // ������� ���� - ���� ���� ����� �������
    while (!q.empty())
    {
        // ����� ������ �� ���
        int v = q.front();
        q.pop();
        // ����������� �� ���� �� �������
        for (int i = 0; i < (int)edges[v].size(); ++i)
        {
            // ���� ����� �����
            if (mark[edges[v][i]] == 0)
            {
                // �� ��������� ����������
                d[edges[v][i]] = d[v] + 1;
                // � �� ���������� �����
                mark[edges[v][i]] = 1;
                q.push(edges[v][i]);
            }
        }
    }
}