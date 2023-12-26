#pragma once
#include <QMap>
#include <QString>
#include <QList>
#include <QQueue>
#include <iostream>
#include <climits>
#include <qdebug.h>

// 函数：执行拓扑排序
bool topologicalSort(const QMap<QString, QMap<QString, int>>& graph, QList<QString>& sortedNodes) {
	// 统计每个节点的入度
	QMap<QString, int> inDegree;
	for (const auto& node : graph.keys()) {
		for (const auto& edge : graph[node].keys()) {
			inDegree[edge]++;
			if (!inDegree.contains(node)) {
				inDegree[node] = 0;
			}
		}
	}

	// 将所有入度为0的节点加入队列
	QQueue<QString> q;
	for (const auto& node : inDegree.keys()) {
		if (inDegree[node] == 0) {
			q.enqueue(node);
		}
	}

	while (!q.isEmpty()) {
		QString node = q.dequeue();
		sortedNodes.append(node);

		for (const auto& edge : graph[node].keys()) {
			inDegree[edge]--;
			if (inDegree[edge] == 0) {
				q.enqueue(edge);
			}
		}
	}

	// 检查是否有环（拓扑排序结果节点数是否与图的节点数相等）
	return sortedNodes.size() == inDegree.size();
}

// 函数：找到所有关键活动
QMap<QString, QMap<QString, bool>> findCriticalActivities(const QMap<QString, QMap<QString, int>>& graph) {
	QList<QString> topoSortedNodes;

	// 执行拓扑排序
	if (!topologicalSort(graph, topoSortedNodes)) {
		std::cerr << "Graph has a cycle. Cannot find critical activities." << std::endl;
		return QMap<QString, QMap<QString, bool>>();
	}

	QMap<QString, int> earliestStartTimes;
	QMap<QString, int> latestStartTimes;

	for (const auto& node : topoSortedNodes) {
		earliestStartTimes[node] = 0;
	}

	// 正向计算最早开始时间
	for (const auto& node : topoSortedNodes) {
		for (const auto& edge : graph[node].keys()) {
			int weight = graph[node][edge];
			if (earliestStartTimes[edge] < earliestStartTimes[node] + weight) {
				earliestStartTimes[edge] = earliestStartTimes[node] + weight;
			}
		}
	}

	// 初始化最晚开始时间
	QString lastNode = topoSortedNodes.last();
	int projectDuration = earliestStartTimes[lastNode];
	for (const auto& node : topoSortedNodes) {
		latestStartTimes[node] = projectDuration;
	}

	// 反向计算最晚开始时间
	for (int i = topoSortedNodes.size() - 1; i >= 0; --i) {
		QString node = topoSortedNodes[i];
		for (const auto& toNode : graph[node].keys()) {
			int weight = graph[node][toNode];
			if (latestStartTimes[node] > latestStartTimes[toNode] - weight) {
				latestStartTimes[node] = latestStartTimes[toNode] - weight;
			}
		}
	}

	QMap<QString, QMap<QString, bool>>  ret;
	// 查找关键活动
	for (const auto& node : topoSortedNodes) {
		for (const auto& toNode : graph[node].keys()) {
			if (earliestStartTimes[node] == latestStartTimes[toNode] - graph[node][toNode]) {
				ret[node][toNode] = true;
			}
		}
	}
	return ret;
}
