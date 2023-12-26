import 'package:flutter/material.dart';
import 'package:flutter/services.dart';

void main() {
  runApp(MyApp());
}

class MyApp extends StatelessWidget {
  @override
  Widget build(BuildContext context) {
    return const MaterialApp(
      title: 'Josephus Game',
      debugShowCheckedModeBanner: false,
      home: JosephusGame(),
    );
  }
}

class JosephusGame extends StatefulWidget {
  const JosephusGame({super.key});

  @override
  _JosephusGameState createState() => _JosephusGameState();
}

class _JosephusGameState extends State<JosephusGame> {
  final TextEditingController inputController = TextEditingController();
  final TextEditingController inputStartEndController = TextEditingController();
  final TextEditingController inputToIndexController = TextEditingController();
  final TextEditingController indexController = TextEditingController();
  final TextEditingController indexRemoveController = TextEditingController();
  final TextEditingController skipCountController = TextEditingController();
  int lastNumber = 0;
  List<int> removedList = [];
  List<int> peopleList = [];
  List<int> _peopleList = [];

  Future<void> _playJosephusGame() async {
    int totalPeople = peopleList.length;
    int skipCount = int.tryParse(skipCountController.text) ?? 0;

    if (totalPeople > 0 && skipCount > 0) {
      int index = 0;
      while (peopleList.length > 1) {
        index = (index + skipCount - 1) % peopleList.length;
        await Future.delayed(const Duration(seconds: 1));
        removedList.add(peopleList.removeAt(index));
        setState(() {});
      }
      lastNumber = peopleList.first;
      // Reset input fields and eliminated list
      inputController.clear();
      inputStartEndController.clear();
      inputToIndexController.clear();
      indexController.clear();
      indexRemoveController.clear();
      skipCountController.clear();
      setState(() {
        removedList = removedList;
        removedList.sort();
        peopleList = removedList;
      });
    }
  }

  Future<void> _restart() async {
    inputController.clear();
    inputStartEndController.clear();
    inputToIndexController.clear();
    indexController.clear();
    indexRemoveController.clear();
    skipCountController.clear();
    setState(() {
      removedList.clear();
      lastNumber = 0;
      _peopleList.clear();
      peopleList.clear();
    });
  }

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: AppBar(
        title: const Text('Josephus Game'),
      ),
      body: Row(
        crossAxisAlignment: CrossAxisAlignment.start,
        mainAxisAlignment: MainAxisAlignment.start,
        children: [
          Expanded(
            flex: 1,
            child: Container(
              color: Colors.grey.withOpacity(0.1),
              padding: const EdgeInsets.all(16.0),
              child: Column(
                crossAxisAlignment: CrossAxisAlignment.start,
                mainAxisAlignment: MainAxisAlignment.start,
                children: [
                  const Text('Insert'),
                  const Divider(),
                  Row(
                    children: [
                      Expanded(
                        child: TextField(
                          style: const TextStyle(fontSize: 16),
                          decoration: InputDecoration(
                            contentPadding: const EdgeInsets.symmetric(horizontal: 10),
                            border: OutlineInputBorder(
                              borderRadius: BorderRadius.circular(8),
                            ),
                            hintText: 'number',
                          ),
                          inputFormatters: [FilteringTextInputFormatter.digitsOnly],
                          controller: inputController,
                          keyboardType: TextInputType.number,
                        ),
                      ),
                      const SizedBox(width: 10),
                      ElevatedButton(
                        onPressed: () {
                          if (!peopleList.contains(int.parse(inputController.text)) &&
                              !_peopleList.contains(int.parse(inputController.text))) {
                            setState(() => peopleList.add(int.parse(inputController.text)));
                            setState(() => _peopleList.add(int.parse(inputController.text)));
                          }
                        },
                        child: const Text('Insert'),
                      ),
                      const SizedBox(width: 10),
                      ElevatedButton(
                        onPressed: () {
                          setState(() {
                            peopleList.clear();
                            _peopleList.clear();
                            removedList.clear();
                          });
                        },
                        child: const Text('Clear'),
                      ),
                    ],
                  ),
                  const SizedBox(height: 30),
                  const Text('Add to start or end'),
                  const Divider(),
                  Row(
                    children: [
                      Expanded(
                        child: TextField(
                          style: const TextStyle(fontSize: 16),
                          decoration: InputDecoration(
                            contentPadding: const EdgeInsets.symmetric(horizontal: 10),
                            border: OutlineInputBorder(
                              borderRadius: BorderRadius.circular(8),
                            ),
                            hintText: 'number',
                          ),
                          inputFormatters: [FilteringTextInputFormatter.digitsOnly],
                          controller: inputStartEndController,
                          keyboardType: TextInputType.number,
                        ),
                      ),
                      const SizedBox(width: 10),
                      ElevatedButton(
                        onPressed: () {
                          if (!peopleList.contains(int.parse(inputStartEndController.text)) &&
                              !_peopleList.contains(int.parse(inputStartEndController.text))) {
                            setState(
                              () => peopleList.insert(
                                0,
                                int.parse(inputStartEndController.text),
                              ),
                            );
                            setState(
                              () => _peopleList.insert(
                                0,
                                int.parse(inputStartEndController.text),
                              ),
                            );
                          }
                        },
                        child: const Text('Add to start'),
                      ),
                      const SizedBox(width: 10),
                      ElevatedButton(
                        onPressed: () {
                          if (!peopleList.contains(int.parse(inputStartEndController.text)) &&
                              !_peopleList.contains(int.parse(inputStartEndController.text))) {
                            setState(
                              () => peopleList.insert(
                                peopleList.length,
                                int.parse(inputStartEndController.text),
                              ),
                            );
                            setState(
                              () => _peopleList.insert(
                                _peopleList.length,
                                int.parse(inputStartEndController.text),
                              ),
                            );
                          }
                        },
                        child: const Text('Add to end'),
                      ),
                    ],
                  ),
                  const SizedBox(height: 30),
                  const Text('Add to specific index'),
                  const Divider(),
                  Row(
                    children: [
                      Expanded(
                        child: TextField(
                          style: const TextStyle(fontSize: 16),
                          decoration: InputDecoration(
                            contentPadding: const EdgeInsets.symmetric(horizontal: 10),
                            border: OutlineInputBorder(
                              borderRadius: BorderRadius.circular(8),
                            ),
                            hintText: 'number',
                          ),
                          inputFormatters: [FilteringTextInputFormatter.digitsOnly],
                          controller: inputToIndexController,
                          keyboardType: TextInputType.number,
                        ),
                      ),
                      const SizedBox(width: 10),
                      Expanded(
                        child: TextField(
                          style: const TextStyle(fontSize: 16),
                          decoration: InputDecoration(
                            contentPadding: const EdgeInsets.symmetric(horizontal: 10),
                            border: OutlineInputBorder(
                              borderRadius: BorderRadius.circular(8),
                            ),
                            hintText: 'index',
                          ),
                          inputFormatters: [FilteringTextInputFormatter.digitsOnly],
                          controller: indexController,
                          keyboardType: TextInputType.number,
                        ),
                      ),
                      const SizedBox(width: 10),
                      ElevatedButton(
                        onPressed: () {
                          if (!peopleList.contains(int.parse(inputToIndexController.text)) &&
                              !_peopleList.contains(int.parse(inputToIndexController.text))) {
                            setState(
                              () => peopleList.insert(
                                int.parse(indexController.text),
                                int.parse(inputToIndexController.text),
                              ),
                            );
                            setState(
                              () => _peopleList.insert(
                                int.parse(indexController.text),
                                int.parse(inputToIndexController.text),
                              ),
                            );
                          }
                        },
                        child: const Text('Add'),
                      ),
                    ],
                  ),
                  const SizedBox(height: 30),
                  const Text('Remove'),
                  const Divider(),
                  Row(
                    children: [
                      Expanded(
                        child: TextField(
                          style: const TextStyle(fontSize: 16),
                          decoration: InputDecoration(
                            contentPadding: const EdgeInsets.symmetric(horizontal: 10),
                            border: OutlineInputBorder(
                              borderRadius: BorderRadius.circular(8),
                            ),
                            hintText: 'index',
                          ),
                          inputFormatters: [FilteringTextInputFormatter.digitsOnly],
                          controller: indexRemoveController,
                          keyboardType: TextInputType.number,
                        ),
                      ),
                      const SizedBox(width: 10),
                      ElevatedButton(
                        onPressed: () {
                          if (peopleList.isNotEmpty) {
                            setState(() => peopleList.removeAt(0));
                          }
                          if (_peopleList.isNotEmpty) {
                            setState(() => _peopleList.removeAt(0));
                          }
                        },
                        child: const Text('first'),
                      ),
                      const SizedBox(width: 10),
                      ElevatedButton(
                        onPressed: () {
                          if (peopleList.isNotEmpty) {
                            setState(() => peopleList.removeLast());
                          }
                          if (_peopleList.isNotEmpty) {
                            setState(() => _peopleList.removeLast());
                          }
                        },
                        child: const Text('last'),
                      ),
                      const SizedBox(width: 10),
                      ElevatedButton(
                        onPressed: () {
                          if (indexRemoveController.text != '') {
                            if (peopleList.isNotEmpty) {
                              setState(
                                  () => peopleList.removeAt(int.parse(indexRemoveController.text)));
                            }
                            if (_peopleList.isNotEmpty) {
                              setState(() =>
                                  _peopleList.removeAt(int.parse(indexRemoveController.text)));
                            }
                          }
                        },
                        child: const Text('remove'),
                      ),
                    ],
                  ),
                  const SizedBox(height: 30),
                  TextField(
                    style: const TextStyle(fontSize: 16),
                    decoration: InputDecoration(
                      contentPadding: const EdgeInsets.symmetric(horizontal: 10),
                      border: OutlineInputBorder(
                        borderRadius: BorderRadius.circular(8),
                      ),
                      hintText: 'skip count',
                    ),
                    controller: skipCountController,
                    inputFormatters: [FilteringTextInputFormatter.digitsOnly],
                    keyboardType: TextInputType.number,
                  ),
                  const SizedBox(height: 30),
                  ElevatedButton(
                    onPressed: _playJosephusGame,
                    child: const Text('Play Josephus Game'),
                  ),
                  const SizedBox(height: 30),
                  ElevatedButton(
                    onPressed: _restart,
                    child: const Text('Restart'),
                  ),
                ],
              ),
            ),
          ),
          Expanded(
            flex: 3,
            child: Padding(
              padding: const EdgeInsets.symmetric(horizontal: 20),
              child: Column(
                crossAxisAlignment: CrossAxisAlignment.center,
                mainAxisAlignment: MainAxisAlignment.center,
                children: [
                  SizedBox(
                    height: 50,
                    child: ListView.builder(
                      scrollDirection: Axis.horizontal,
                      itemCount: _peopleList.length,
                      itemBuilder: (context, i) => Row(
                        crossAxisAlignment: CrossAxisAlignment.center,
                        mainAxisAlignment: MainAxisAlignment.center,
                        children: [
                          Container(
                            width: 50,
                            height: 50,
                            decoration: BoxDecoration(
                              color: removedList.isNotEmpty && removedList.contains(_peopleList[i])
                                  ? Colors.red
                                  : removedList.isNotEmpty && !removedList.contains(_peopleList[i])
                                      ? Colors.green
                                      : Colors.blue,
                            ),
                            child: Center(
                              child: Text(
                                _peopleList[i].toString(),
                                style: const TextStyle(
                                  color: Colors.white,
                                  fontSize: 22,
                                ),
                              ),
                            ),
                          ),
                          if (_peopleList[i] != _peopleList.last)
                            Padding(
                              padding: const EdgeInsets.symmetric(horizontal: 4),
                              child: Icon(
                                Icons.arrow_right_alt_rounded,
                                size: 40,
                                color: Colors.black.withOpacity(0.5),
                              ),
                            ),
                        ],
                      ),
                    ),
                  )
                ],
              ),
            ),
          ),
        ],
      ),
    );
  }
}
