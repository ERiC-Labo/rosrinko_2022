# Week3
今週はImage型のtopicをsubscribeして、画像を処理したあとpublishしてみましょう.
# 準備
sudo apt install ros-noetic-usb-cam
sudo apt install ros-noetic-image-view
# 参考プログラム
week3/scripts/RGB2GRAY.pyを見てください。
ROSのmsgのImg型はそのままopencvを使えないので、CvBridgeを使って変換してから処理します。
publishするときもCvBridgeを使ってImg型のmsgに変換します。
# 参考プログラムの使い方
- ターミナル1でroscore
- ターミナル2でソースしたあと、rosrun usb_cam usb_cam_node
- ターミナル3でソースしたあと、rosrun week3 RGB2GRAY  
- ターミナル4でrvizを実行してから確認
# 課題
リアルタイムで顔検出します。
opencvには標準で顔検出できるパッケージがあるので探してみてください。
