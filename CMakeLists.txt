cmake_minimum_required(VERSION 3.8)
project(programming_miniproject)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
        Client/Client/Client.cpp
        Client/Client/stdafx.cpp
        Client/Client/stdafx.h
        Client/Client/targetver.h
        "External Libraries/SFML/examples/ftp/Ftp.cpp"
        "External Libraries/SFML/examples/opengl/OpenGL.cpp"
        "External Libraries/SFML/examples/pong/Pong.cpp"
        "External Libraries/SFML/examples/shader/Effect.hpp"
        "External Libraries/SFML/examples/shader/Shader.cpp"
        "External Libraries/SFML/examples/sockets/Sockets.cpp"
        "External Libraries/SFML/examples/sockets/TCP.cpp"
        "External Libraries/SFML/examples/sockets/UDP.cpp"
        "External Libraries/SFML/examples/sound/Sound.cpp"
        "External Libraries/SFML/examples/sound-capture/SoundCapture.cpp"
        "External Libraries/SFML/examples/voip/Client.cpp"
        "External Libraries/SFML/examples/voip/Server.cpp"
        "External Libraries/SFML/examples/voip/VoIP.cpp"
        "External Libraries/SFML/examples/win32/Win32.cpp"
        "External Libraries/SFML/examples/window/Window.cpp"
        "External Libraries/SFML/include/SFML/Audio/AlResource.hpp"
        "External Libraries/SFML/include/SFML/Audio/Export.hpp"
        "External Libraries/SFML/include/SFML/Audio/InputSoundFile.hpp"
        "External Libraries/SFML/include/SFML/Audio/Listener.hpp"
        "External Libraries/SFML/include/SFML/Audio/Music.hpp"
        "External Libraries/SFML/include/SFML/Audio/OutputSoundFile.hpp"
        "External Libraries/SFML/include/SFML/Audio/Sound.hpp"
        "External Libraries/SFML/include/SFML/Audio/SoundBuffer.hpp"
        "External Libraries/SFML/include/SFML/Audio/SoundBufferRecorder.hpp"
        "External Libraries/SFML/include/SFML/Audio/SoundFileFactory.hpp"
        "External Libraries/SFML/include/SFML/Audio/SoundFileReader.hpp"
        "External Libraries/SFML/include/SFML/Audio/SoundFileWriter.hpp"
        "External Libraries/SFML/include/SFML/Audio/SoundRecorder.hpp"
        "External Libraries/SFML/include/SFML/Audio/SoundSource.hpp"
        "External Libraries/SFML/include/SFML/Audio/SoundStream.hpp"
        "External Libraries/SFML/include/SFML/Graphics/BlendMode.hpp"
        "External Libraries/SFML/include/SFML/Graphics/CircleShape.hpp"
        "External Libraries/SFML/include/SFML/Graphics/Color.hpp"
        "External Libraries/SFML/include/SFML/Graphics/ConvexShape.hpp"
        "External Libraries/SFML/include/SFML/Graphics/Drawable.hpp"
        "External Libraries/SFML/include/SFML/Graphics/Export.hpp"
        "External Libraries/SFML/include/SFML/Graphics/Font.hpp"
        "External Libraries/SFML/include/SFML/Graphics/Glsl.hpp"
        "External Libraries/SFML/include/SFML/Graphics/Glyph.hpp"
        "External Libraries/SFML/include/SFML/Graphics/Image.hpp"
        "External Libraries/SFML/include/SFML/Graphics/PrimitiveType.hpp"
        "External Libraries/SFML/include/SFML/Graphics/Rect.hpp"
        "External Libraries/SFML/include/SFML/Graphics/RectangleShape.hpp"
        "External Libraries/SFML/include/SFML/Graphics/RenderStates.hpp"
        "External Libraries/SFML/include/SFML/Graphics/RenderTarget.hpp"
        "External Libraries/SFML/include/SFML/Graphics/RenderTexture.hpp"
        "External Libraries/SFML/include/SFML/Graphics/RenderWindow.hpp"
        "External Libraries/SFML/include/SFML/Graphics/Shader.hpp"
        "External Libraries/SFML/include/SFML/Graphics/Shape.hpp"
        "External Libraries/SFML/include/SFML/Graphics/Sprite.hpp"
        "External Libraries/SFML/include/SFML/Graphics/Text.hpp"
        "External Libraries/SFML/include/SFML/Graphics/Texture.hpp"
        "External Libraries/SFML/include/SFML/Graphics/Transform.hpp"
        "External Libraries/SFML/include/SFML/Graphics/Transformable.hpp"
        "External Libraries/SFML/include/SFML/Graphics/Vertex.hpp"
        "External Libraries/SFML/include/SFML/Graphics/VertexArray.hpp"
        "External Libraries/SFML/include/SFML/Graphics/View.hpp"
        "External Libraries/SFML/include/SFML/Network/Export.hpp"
        "External Libraries/SFML/include/SFML/Network/Ftp.hpp"
        "External Libraries/SFML/include/SFML/Network/Http.hpp"
        "External Libraries/SFML/include/SFML/Network/IpAddress.hpp"
        "External Libraries/SFML/include/SFML/Network/Packet.hpp"
        "External Libraries/SFML/include/SFML/Network/Socket.hpp"
        "External Libraries/SFML/include/SFML/Network/SocketHandle.hpp"
        "External Libraries/SFML/include/SFML/Network/SocketSelector.hpp"
        "External Libraries/SFML/include/SFML/Network/TcpListener.hpp"
        "External Libraries/SFML/include/SFML/Network/TcpSocket.hpp"
        "External Libraries/SFML/include/SFML/Network/UdpSocket.hpp"
        "External Libraries/SFML/include/SFML/System/Clock.hpp"
        "External Libraries/SFML/include/SFML/System/Err.hpp"
        "External Libraries/SFML/include/SFML/System/Export.hpp"
        "External Libraries/SFML/include/SFML/System/FileInputStream.hpp"
        "External Libraries/SFML/include/SFML/System/InputStream.hpp"
        "External Libraries/SFML/include/SFML/System/Lock.hpp"
        "External Libraries/SFML/include/SFML/System/MemoryInputStream.hpp"
        "External Libraries/SFML/include/SFML/System/Mutex.hpp"
        "External Libraries/SFML/include/SFML/System/NativeActivity.hpp"
        "External Libraries/SFML/include/SFML/System/NonCopyable.hpp"
        "External Libraries/SFML/include/SFML/System/Sleep.hpp"
        "External Libraries/SFML/include/SFML/System/String.hpp"
        "External Libraries/SFML/include/SFML/System/Thread.hpp"
        "External Libraries/SFML/include/SFML/System/ThreadLocal.hpp"
        "External Libraries/SFML/include/SFML/System/ThreadLocalPtr.hpp"
        "External Libraries/SFML/include/SFML/System/Time.hpp"
        "External Libraries/SFML/include/SFML/System/Utf.hpp"
        "External Libraries/SFML/include/SFML/System/Vector2.hpp"
        "External Libraries/SFML/include/SFML/System/Vector3.hpp"
        "External Libraries/SFML/include/SFML/Window/Context.hpp"
        "External Libraries/SFML/include/SFML/Window/ContextSettings.hpp"
        "External Libraries/SFML/include/SFML/Window/Event.hpp"
        "External Libraries/SFML/include/SFML/Window/Export.hpp"
        "External Libraries/SFML/include/SFML/Window/GlResource.hpp"
        "External Libraries/SFML/include/SFML/Window/Joystick.hpp"
        "External Libraries/SFML/include/SFML/Window/Keyboard.hpp"
        "External Libraries/SFML/include/SFML/Window/Mouse.hpp"
        "External Libraries/SFML/include/SFML/Window/Sensor.hpp"
        "External Libraries/SFML/include/SFML/Window/Touch.hpp"
        "External Libraries/SFML/include/SFML/Window/VideoMode.hpp"
        "External Libraries/SFML/include/SFML/Window/Window.hpp"
        "External Libraries/SFML/include/SFML/Window/WindowHandle.hpp"
        "External Libraries/SFML/include/SFML/Window/WindowStyle.hpp"
        "External Libraries/SFML/include/SFML/Audio.hpp"
        "External Libraries/SFML/include/SFML/Config.hpp"
        "External Libraries/SFML/include/SFML/Graphics.hpp"
        "External Libraries/SFML/include/SFML/Main.hpp"
        "External Libraries/SFML/include/SFML/Network.hpp"
        "External Libraries/SFML/include/SFML/OpenGL.hpp"
        "External Libraries/SFML/include/SFML/System.hpp"
        "External Libraries/SFML/include/SFML/Window.hpp"
        santa_game/santa_game/ConsoleApplication3.cpp
        santa_game/santa_game/Drops.cpp
        santa_game/santa_game/Drops.h
        santa_game/santa_game/Elf.cpp
        santa_game/santa_game/Elf.h
        santa_game/santa_game/Field.cpp
        santa_game/santa_game/Field.h
        santa_game/santa_game/Player.cpp
        santa_game/santa_game/Player.h
        santa_game/santa_game/Props.cpp
        santa_game/santa_game/Props.h
        santa_game/santa_game/Santa.cpp
        santa_game/santa_game/Santa.h
        santa_game/santa_game/santa_game.cpp
        santa_game/santa_game/stdafx.cpp
        santa_game/santa_game/stdafx.h
        santa_game/santa_game/targetver.h
        santa_game/santa_game.sln)

add_executable(programming_miniproject ${SOURCE_FILES})