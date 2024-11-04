# PasMan - Password Manager

PasMan to desktopowy menedżer haseł opracowany jako projekt studencki. Aplikacja umożliwia bezpieczne przechowywanie, organizowanie oraz generowanie haseł. Dzięki wykorzystaniu szyfrowania zapewnia wysoki poziom ochrony przechowywanych danych, a jednocześnie jest intuicyjna i prosta w obsłudze.

## Funkcje

PasMan oferuje szeroki zakres funkcjonalności dla zarządzania hasłami:
- **Logowanie i zarządzanie użytkownikiem**: Aplikacja obsługuje jednego użytkownika, który po początkowej rejestracji korzysta z hasła dostępu do menedżera haseł.
- **Wyświetlanie zapisanych haseł**: Użytkownik ma możliwość przeglądania zapisanych haseł oraz ich szczegółów.
- **Dodawanie nowych haseł**: Możliwość dodawania nowych wpisów, które mogą zawierać informacje takie jak: nazwa, username, hasło, kategoria, URL oraz notatki.
- **Edycja i usuwanie haseł**: Użytkownik może modyfikować i usuwać zapisane hasła.
- **Generowanie haseł**: Aplikacja zawiera generator, który umożliwia tworzenie silnych haseł.
- **Sprawdzanie siły hasła**: Specjalny dialog pozwala na sprawdzenie siły hasła, a także oferuje szacunkowy czas na złamanie hasła metodą brute-force oraz długość zaszyfrowanego hasła w bitach.
- **Bezpieczne szyfrowanie**: Wszystkie dane są zaszyfrowane, aby zapewnić bezpieczeństwo użytkownika.

## Technologie

PasMan korzysta z silnych algorytmów szyfrowania, takich jak AES-256, które gwarantują ochronę przechowywanych haseł i innych wrażliwych danych użytkownika. Każdy wpis jest hashowany i przechowywany w bezpiecznym formacie, co zapobiega nieautoryzowanemu dostępowi do informacji.

## Wymagania

Aplikacja została opracowana z uwzględnieniem kluczowych wymagań funkcjonalnych i pozafunkcjonalnych:

### Wymagania funkcjonalne
- **FR.001**: Logowanie użytkownika (wysoki priorytet)
- **FR.002**: Zarządzanie hasłami, tj. wyświetlanie, dodawanie, edytowanie oraz usuwanie haseł
- **FR.003**: Generowanie silnych haseł (średni priorytet)
- **FR.004**: Sprawdzanie siły haseł oraz udzielanie informacji o czasie złamania metodą brute-force
- **FR.005**: Szyfrowanie i przechowywanie haseł w formacie zabezpieczonym

### Wymagania pozafunkcjonalne
- **PF.001**: Bezpieczeństwo – wykorzystanie szyfrowania AES-256
- **PF.002**: Wydajność – płynne działanie bez opóźnień
- **PF.003**: Intuicyjny interfejs użytkownika

## Instalacja i uruchomienie

Aby uruchomić projekt PasMan:

1. Pobierz plik `projekt.rar` i rozpakuj wszystkie pliki.
2. Zdekompresowany folder zawiera pełen zestaw plików potrzebnych do uruchomienia aplikacji oraz dokumentację.
3. Uruchom aplikację zgodnie z instrukcjami w dokumentacji zawartej w `projekt.rar`.

## Użycie

Po uruchomieniu aplikacji użytkownik może:
1. Zalogować się przy użyciu utworzonego wcześniej hasła.
2. Przeglądać zapisane hasła, dodawać nowe, edytować istniejące oraz usuwać niepotrzebne.
3. Wygenerować silne hasło, dostosowane do swoich potrzeb.
4. Przeanalizować siłę dowolnego hasła, uzyskując dodatkowe informacje o jego bezpieczeństwie.

## Bezpieczeństwo i szyfrowanie

Wszystkie dane w PasMan są szyfrowane za pomocą algorytmu AES-256, co zapewnia wysoki poziom ochrony danych użytkownika. Każde zapisane hasło jest hashowane, aby uniemożliwić dostęp osobom niepowołanym. Dzięki takiemu podejściu PasMan spełnia najwyższe standardy bezpieczeństwa i pozwala użytkownikom na wygodne zarządzanie swoimi hasłami w jednym miejscu.

## Autor

Autorem jest Olaf Wojda 160203.
Projekt PasMan został opracowany jako część pracy studenckiej.

## Licencja

Projekt PasMan jest dostępny wyłącznie do użytku edukacyjnego za zgodą autora.
