// HTML, CSS и JavaScript для веб-страницы, используем C++ Raw String Literal для удобства

const char* HTML_CONTENT = R"RAW(
<!DOCTYPE html>
<html lang="ru">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>ПАТРИОТ Control</title>
        <link rel="shortcut icon" href="data:image/svg+xml;base64,PD94bWwgdmVyc2lvbj0iMS4wIiBlbmNvZGluZz0idXRmLTgiPz4KPCEtLSBHZW5lcmF0b3I6IEF
        kb2JlIElsbHVzdHJhdG9yIDI3LjYuMSwgU1ZHIEV4cG9ydCBQbHVnLUluIC4gU1ZHIFZlcnNpb246IDYuMDAgQnVpbGQgMCkgIC0tPgo8c3ZnIHZlcnNpb249IjEuMSIgaWQ9
        ItCh0LvQvtC5XzEiIHhtbG5zPSJodHRwOi8vd3d3LnczLm9yZy8yMDAwL3N2ZyIgeG1sbnM6eGxpbms9Imh0dHA6Ly93d3cudzMub3JnLzE5OTkveGxpbmsiIHg9IjBweCIge
        T0iMHB4IgoJIHZpZXdCb3g9IjAgMCAyMDAgMjAwIiBzdHlsZT0iZW5hYmxlLWJhY2tncm91bmQ6bmV3IDAgMCAyMDAgMjAwOyIgeG1sOnNwYWNlPSJwcmVzZXJ2ZSI+CjxzdH
        lsZSB0eXBlPSJ0ZXh0L2NzcyI+Cgkuc3Qwe2ZpbGw6I0ZGRkZGRjt9Cgkuc3Qxe2ZpbGw6I0ZGMDAwMDt9Cjwvc3R5bGU+CjxnPgoJPHBhdGggZD0iTTE2Mi42LDIwMEgzNy4
        0QzE2LjgsMjAwLDAsMTgzLjIsMCwxNjIuNlYzNy40QzAsMTYuOCwxNi44LDAsMzcuNCwwaDEyNS4xQzE4My4yLDAsMjAwLDE2LjgsMjAwLDM3LjR2MTI1LjEKCQlDMjAwLDE4
        My4yLDE4My4yLDIwMCwxNjIuNiwyMDB6Ii8+Cgk8Zz4KCQk8cGF0aCBjbGFzcz0ic3QwIiBkPSJNMTcxLjQsNjAuNGMwLTExLjctOS41LTIxLjEtMjEuMS0yMS4xSDQ5LjhjL
        TExLjcsMC0yMS4xLDkuNS0yMS4xLDIxLjF2MTAwLjNoMzEuOVY3Ni42CgkJCWMwLTIuOSwyLjQtNS4zLDUuMy01LjNoNjguMmMyLjksMCw1LjMsMi40LDUuMyw1LjN2ODQuMW
        gzMS45TDE3MS40LDYwLjRMMTcxLjQsNjAuNHoiLz4KCTwvZz4KCTxjaXJjbGUgY2xhc3M9InN0MSIgY3g9IjEwMCIgY3k9IjExMi4yIiByPSIxNi4zIi8+CjwvZz4KPC9zdmc
    +Cg==" />
    <style>
        body { font-family: -apple-system, BlinkMacSystemFont, "Segoe UI", Roboto, Helvetica, Arial, sans-serif; background-color: #f0f2f5; display: flex; justify-content: center; align-items: center; min-height: 100vh; margin: 0; }
        .container { background-color: #fff; padding: 30px; border-radius: 5px; box-shadow: 0 6px 12px rgba(0,0,0,0.1); width: 90%; max-width: 400px; }
        h1 { text-align: center; color: #333; font-size: 2em;}
        h2 { text-align: center; color: #333; font-size: 1em;}
        /* стиль для названия устройства */
        .name { text-align: center; color: #333; margin-bottom: 25px; }
        /* стиль для модели устройства */
        .model { text-align: center; color: #333; margin-bottom: 16px; }
        /* Стили для сетки кнопок */
        #switches-grid {
            display: grid;
            grid-template-columns: repeat(2, 1fr); /* 2 колонки */
            gap: 12px; /* Промежуток между кнопками */
            margin-bottom: 25px;
        }
        .grid-btn {
            background-color: #e9ecef; /* Цвет выключенной кнопки */
            color: #495057; /* Цвет текста выключенной кнопки */
            border: none;
            border-radius: 10px;
            padding: 15px 5px;
            font-size: 1em;
            font-weight: 900;
            cursor: pointer;
            transition: all 0.3s ease;
            text-align: center;
            min-height: 70px; /* Минимальная высота для выравнивания */
            display: flex;
            justify-content: center;
            align-items: center;
        }
        .grid-btn.active {
            background-color: #e74c3c; /* Цвет включенной кнопки (красный) */
            color: white;
            box-shadow: 0 4px 12px rgba(231, 76, 60, 0.4);
            transform: translateY(-2px);
        }
        .grid-btn:active { transform: translateY(-2px) scale(0.98); }
        
        /* Стили для главных кнопок управления */
        .master-controls {
            display: flex;
            justify-content: space-between;
            gap: 15px;
            padding-top: 20px;
            border-top: 2px solid #f0f2f5;
        }
        
        /* Стили для общих кнопок */
        .master-btn {
            flex-grow: 1;
            padding: 12px;
            font-size: 1em;
            font-weight: 700;
            border: none;
            border-radius: 8px;
            cursor: pointer;
            transition: background-color 0.3s, transform 0.1s;
            color: white;
        }
        .master-btn:active { transform: scale(0.98); }
        #master-on-btn { background-color: #28a745; }
        #master-off-btn { background-color: #6c757d; }

        /* Стили для низа страницы */
        .footer_up { display: flex; justify-content: space-between; align-items: center; margin-top: 25px; padding-top: 25px; border-top: 1px solid #eee; font-size: 0.9em; color: #888; }
        .footer_down { display: flex; justify-content: space-between; align-items: center; margin-top: 5px; padding-top: 5px; border-top: 0px solid #eee; font-size: 0.9em; color: #888; }
        #footer-center.connected { color: #28a745; }
        #footer-center.disconnected { color: #e74c3c; }
    </style>
</head>

<body>
    <div class="container">
        <div align="center"><img src="data:image/svg+xml;base64,PHN2ZyB3aWR0aD0iODM3IiBoZWlnaHQ9IjkwIiB2aWV3Qm94PSIwIDAgODM3IDkwIiBmaWxsPSJub25lIiB4bWxucz0iaHR0cDovL3d3dy53My5vcmcvMjAwMC9zdmciPgo8ZyBjbGlwLXBhdGg9InVybCgjY2xpcDBfMV84KSI+CjxwYXRoIGQ9Ik
        02OTguMTY0IDBINjE2Ljg2OUM2MDguMTY0IDAgNjAxLjIyOSA3LjA4MTk3IDYwMS4yMjkgMTUuNjM5M1Y3NC4zNjA3QzYwMS4yMjkgODMuMDY1NiA2MDguMzExIDkwIDYxNi44NjkgOTBINjk4LjE2NEM3MDYuODY5IDkwIDcxMy44MDMgODIuOTE4IDcxMy44MDMgNzQuMzYwN1YxNS42MzkzQzcx
        My44MDMgNy4wODE5NyA3MDYuNzIxIDAgNjk4LjE2NCAwWk02OTAuMDQ5IDYyLjQwOThDNjkwLjA0OSA2NC42MjI5IDY4OC4yNzkgNjYuMzkzNCA2ODYuMDY2IDY2LjM5MzRINjI4LjY3MkM2MjYuNDU5IDY2LjM5MzQgNjI0LjY4OCA2NC42MjI5IDYyNC42ODggNjIuNDA5OFYyNy41OTAyQzYyNC
        42ODggMjUuMzc3MSA2MjYuNDU5IDIzLjYwNjYgNjI4LjY3MiAyMy42MDY2SDY4Ni4wNjZDNjg4LjI3OSAyMy42MDY2IDY5MC4wNDkgMjUuMzc3MSA2OTAuMDQ5IDI3LjU5MDJWNjIuNDA5OFoiIGZpbGw9ImJsYWNrIi8+CjxwYXRoIGQ9Ik05Ni45MzQ0IDBIMTUuNjM5M0M3LjA4MTk3IDAgMCA3
        LjA4MTk3IDAgMTUuNjM5M1Y5MEg3Ljk2NzIxQzE2LjY3MjEgOTAgMjMuNjA2NiA4Mi45MTggMjMuNjA2NiA3NC4zNjA3VjI3LjU5MDJDMjMuNjA2NiAyNS4zNzcxIDI1LjM3NyAyMy42MDY2IDI3LjU5MDIgMjMuNjA2Nkg4NC45ODM2Qzg3LjE5NjcgMjMuNjA2NiA4OC45NjcyIDI1LjM3NzEgOD
        guOTY3MiAyNy41OTAyVjkwSDk2LjkzNDRDMTA1LjYzOSA5MCAxMTIuNTc0IDgyLjkxOCAxMTIuNTc0IDc0LjM2MDdWMTUuNjM5M0MxMTIuNTc0IDcuMDgxOTcgMTA1LjYzOSAwIDk2LjkzNDQgMFoiIGZpbGw9ImJsYWNrIi8+CjxwYXRoIGQ9Ik03NDYuMTE1IDBDNzM3LjQxIDAgNzMwLjMyOCA3
        LjA4MTk3IDczMC4zMjggMTUuNjM5M1YyMy42MDY2SDc3MS42MzlWOTBINzc5LjYwN0M3ODguMzEyIDkwIDc5NS4yNDYgODIuOTE4IDc5NS4yNDYgNzQuMzYwN1YyMy43NTQxSDgyMC43N0M4MjkuNDc1IDIzLjc1NDEgODM2LjQxIDE2LjY3MjEgODM2LjQxIDguMTE0NzVWMEg3NDYuMTE1WiIgZm
        lsbD0iYmxhY2siLz4KPHBhdGggZD0iTTI0Ni42ODkgMEMyMzcuOTg0IDAgMjMxLjA0OSA3LjA4MTk3IDIzMS4wNDkgMTUuNjM5M1YyMy42MDY2SDI3Mi4yMTNWOTBIMjgwLjE4QzI4OC44ODUgOTAgMjk1LjgyIDgyLjkxOCAyOTUuODIgNzQuMzYwN1YyMy43NTQxSDMyMS4zNDRDMzMwLjA0OSAy
        My43NTQxIDMzNi45ODQgMTYuNjcyMSAzMzYuOTg0IDguMTE0NzVWMEgyNDYuNjg5WiIgZmlsbD0iYmxhY2siLz4KPHBhdGggZD0iTTQ0OC42NzIgMEgzNTIuNjIzVjcuOTY3MjFDMzUyLjYyMyAxNi42NzIxIDM1OS43MDUgMjMuNjA2NiAzNjguMjYyIDIzLjYwNjZINDM2LjcyMUM0MzguOTM0ID
        IzLjYwNjYgNDQwLjcwNSAyNS4zNzcxIDQ0MC43MDUgMjcuNTkwMlYzOC42NTU3QzQ0MC43MDUgNDAuODY4OSA0MzguOTM0IDQyLjYzOTMgNDM2LjcyMSA0Mi42MzkzSDM3Ni4zNzdIMzY4LjQxQzM2NC4xMzEgNDIuNjM5MyAzNjAuMTQ4IDQ0LjQwOTggMzU3LjM0NCA0Ny4yMTMxQzM1NC41NDEg
        NTAuMDE2NCAzNTIuNzcxIDU0IDM1Mi43NzEgNTguMjc4N1Y5MEgzNjAuNzM4QzM2OS40NDMgOTAgMzc2LjM3NyA4Mi45MTggMzc2LjM3NyA3NC4zNjA3VjY2LjM5MzRINDQ4LjY3MkM0NTcuMzc3IDY2LjM5MzQgNDY0LjMxMSA1OS4zMTE1IDQ2NC4zMTEgNTAuNzU0MVYxNS43ODY5QzQ2NC4zMT
        EgNy4wODE5NyA0NTcuMzc3IDAgNDQ4LjY3MiAwWiIgZmlsbD0iYmxhY2siLz4KPHBhdGggZD0iTTY1Ny40NDMgMzQuMzc3MUM2NTEuNTQxIDM0LjM3NzEgNjQ2LjgyIDM5LjA5ODQgNjQ2LjgyIDQ1QzY0Ni44MiA1MC45MDE3IDY1MS41NDEgNTUuNjIzIDY1Ny40NDMgNTUuNjIzQzY2My4zNDQg
        NTUuNjIzIDY2OC4wNjYgNTAuOTAxNyA2NjguMDY2IDQ1QzY2OC4yMTMgMzkuMDk4NCA2NjMuMzQ0IDM0LjM3NzEgNjU3LjQ0MyAzNC4zNzcxWiIgZmlsbD0iI0ZGMDAwMCIvPgo8cGF0aCBkPSJNMTgzLjM5MyA3My43NzA1QzE4OS4yNiA3My43NzA1IDE5NC4wMTYgNjkuMDE0NCAxOTQuMDE2ID
        YzLjE0NzVDMTk0LjAxNiA1Ny4yODA3IDE4OS4yNiA1Mi41MjQ2IDE4My4zOTMgNTIuNTI0NkMxNzcuNTI3IDUyLjUyNDYgMTcyLjc3IDU3LjI4MDcgMTcyLjc3IDYzLjE0NzVDMTcyLjc3IDY5LjAxNDQgMTc3LjUyNyA3My43NzA1IDE4My4zOTMgNzMuNzcwNVoiIGZpbGw9IiNGRjAwMDAiLz4K
        PHBhdGggZD0iTTU1Ni4yMjkgNC41NzM3N0w1MDQuNTkgNTYuMzYwN1YxNS42MzkzQzUwNC41OSA2LjkzNDQzIDQ5Ny41MDggMCA0ODguOTUxIDBINDgwLjk4NFY5MEg0OTguMjQ2QzUwMi4zNzcgOTAgNTA2LjM2MSA4OC4zNzcxIDUwOS4zMTEgODUuNDI2Mkw1NjAuOTUxIDMzLjYzOTNWNzQuMz
        YwN0M1NjAuOTUxIDgzLjA2NTYgNTY4LjAzMyA5MCA1NzYuNTkgOTBINTg0LjU1N1YwSDU2Ny4yOTVDNTYzLjE2NCAwIDU1OS4xOCAxLjYyMjk1IDU1Ni4yMjkgNC41NzM3N1oiIGZpbGw9ImJsYWNrIi8+CjxwYXRoIGQ9Ik0xODMuNjg5IDAuMjk1MTA1QzE3NS4yNzkgMC4yOTUxMDUgMTY3LjQ1
        OSA0Ljg2ODg4IDE2My4zMjggMTIuMjQ1OUwxMjAuNTQxIDg5LjU1NzRIMTM4LjY4OUMxNDQuNDQzIDg5LjU1NzQgMTQ5LjYwNyA4Ni40NTkgMTUyLjQxIDgxLjQ0MjZMMTgzLjY4OSAyNC45MzQ0TDIxNC45NjcgODEuNDQyNkMyMTcuNzcgODYuNDU5IDIyMi45MzQgODkuNTU3NCAyMjguNjg5ID
        g5LjU1NzRIMjQ2LjgzNkwyMDQuMDQ5IDEyLjI0NTlDMTk5LjkxOCA1LjAxNjQyIDE5Mi4wOTggMC4yOTUxMDUgMTgzLjY4OSAwLjI5NTEwNVoiIGZpbGw9ImJsYWNrIi8+CjwvZz4KPGRlZnM+CjxjbGlwUGF0aCBpZD0iY2xpcDBfMV84Ij4KPHJlY3Qgd2lkdGg9IjgzNi40MSIgaGVpZ2h0PSI5
        MCIgZmlsbD0id2hpdGUiLz4KPC9jbGlwUGF0aD4KPC9kZWZzPgo8L3N2Zz4K" width="95%" alt="<h1>ПАТРИОТ Control</h1>"/></div>
        
        <h1><div class="name" id="name"></div></h1>
        <h2><div class="model" id="model"></div></h2>
        
        <div id="switches-grid"></div>

        <div class="master-controls">
            <button id="master-on-btn" class="master-btn">Включить всё</button>
            <button id="master-off-btn" class="master-btn">Выключить всё</button>
        </div>

        <div class="footer_up">
            <span id="footer-left"></span>
            <span id="version"></span>
        </div>
        <div class="footer_down">
            <span id="footer-center">Соединение...</span>
            <span id="footer-right">Температура: ...</span>
        </div>
    </div>

<script>
    const connectionStatusEl = document.getElementById('footer-center');
    
    // Функция для отправки запроса на сервер
    async function sendUpdate(id, state) {
        try {
            const response = await fetch(`/update?id=${id}&state=${state ? 1 : 0}`);
            if (!response.ok) throw new Error('Network response was not ok');
            const data = await response.json();
            updatePage(data);
        } catch (error) { console.error('Fetch error:', error); }
    }
    
    // Функция для запроса состояния с сервера (используется для поллинга)
    async function fetchAndUpdateState() {
        try {
            const response = await fetch('/state');
            if (!response.ok) throw new Error('Connection lost');
            const data = await response.json();
            updatePage(data);
            
            // Если запрос успешен - соединение есть
            connectionStatusEl.textContent = 'Соединение есть';
            connectionStatusEl.className = 'connected';

        } catch (error) {
            // Если ошибка - соединения нет
            connectionStatusEl.textContent = 'Соединения нет';
            connectionStatusEl.className = 'disconnected';
        }
    }

    // Общая функция для обновления динамических данных - переключателей и температуры
    function updatePage(data) {
        // Обновляем данные кнопок
        data.states.forEach((state, i) => {
            const btn = document.getElementById(`btn-${i}`);
            if (btn) {
                // Добавляем или убираем класс 'active' для изменения стиля
                btn.classList.toggle('active', state);
                // Сохраняем состояние в data-атрибуте
                btn.dataset.state = state ? '1' : '0';
            }
        });

        // Обновляем значение температуры
        document.getElementById('footer-right').textContent = `Температура: ${data.analog}°C`;
    }

    // Инициализация страницы
    document.addEventListener('DOMContentLoaded', async () => {
        try {
            // Сначала получаем конфигурацию (названия)
            const configResponse = await fetch('/config');
            const config = await configResponse.json();
            
            // Устанавливаем название устройства
            document.getElementById('name').textContent = config.name;

            // Устанавливаем модель устройства
            document.getElementById('model').textContent = config.model;
            
            // Устанавливаем серийный номер
            document.getElementById('footer-left').textContent = config.footer_left;

            // Устанавливаем версию ПО и дату прошивки
            document.getElementById('version').textContent = config.version;
            
            // Генерируем HTML для переключателей на основе полученных названий
            const labels = config.labels;
            const gridContainer = document.getElementById('switches-grid');
            labels.forEach((label, i) => {
                const btn = document.createElement('button');
                btn.id = `btn-${i}`;
                btn.className = 'grid-btn';
                btn.textContent = label; // Текст теперь на самой кнопке
                btn.dataset.state = '0'; // Изначально выключена

                // Добавляем обработчик клика
                btn.addEventListener('click', () => {
                    // Переключаем состояние и отправляем на сервер
                    const newState = btn.dataset.state === '0' ? 1 : 0;
                    sendUpdate(i + 1, newState);
                });
                gridContainer.appendChild(btn);
            });
 
            // Обработчики для общих кнопок
            document.getElementById('master-on-btn').addEventListener('click', () => sendUpdate(0, 1));
            document.getElementById('master-off-btn').addEventListener('click', () => sendUpdate(0, 0));

            // Запрашиваем начальное состояние и запускаем периодический опрос (1с)
            fetchAndUpdateState();
            setInterval(fetchAndUpdateState, 1000);

        } catch (error) {
            console.error('Initialization failed:', error);
            connectionStatusEl.textContent = 'Ошибка загрузки!';
            connectionStatusEl.className = 'disconnected';
        }
    });
</script>
</body>
</html>
)RAW";