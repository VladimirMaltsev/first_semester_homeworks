# Tools

1. Скомпилируйте вот так : gcc yourFile.c -pg -o yourProga -O2 -lc 
   и запустите вашу программу 
2. Запустите Gprof с опцией -b (убирает все лишнее описание) : gprof yourProga -b gmon.out > out.txt
3. Скачайте и скомпилируйте генератор таблиц
4. Запустите программу подав ей на вход данные полученные от Gprofa. Пример для unix ./yourProga < inputSream > outputStream
5. Наслаждайтесь табличкой :)
