/*Задача 2: ImageHelper
Проблема:
Класс `ImageHelper` нарушал принцип единственной ответственности, 
так как он выполнял слишком много различных задач. 

Решение:
Я разделил ответственность класса `ImageHelper` на несколько классов, 
каждый из которых отвечает за одну конкретную задачу. 
Статические методы не требуют создания экземпляра класса для их вызова.
метод не зависит от состояния объекта и не изменяет его*/


#include <iostream>
#include <string>

class Image {
public:
    std::string filename;

    Image(const std::string& filename) : filename(filename) {}

    std::string getFilename() const {
        return filename;
    }
};

class Account {
public:
    std::string username;

    Account(const std::string& username) : username(username) {}

    std::string getUsername() const {
        return username;
    }
};

class Url {
public:
    std::string url;

    Url(const std::string& url) : url(url) {}

    std::string getUrl() const {
        return url;
    }
};

class ImageSaver {
public:
    static std::string Save(const Image& image) {
        return "Image saved successfully: " + image.getFilename();
    }
};

class DuplicateRemover {
public:
    static int DeleteDuplicates() {
        int deletedCount = 2;
        std::cout << "Deleted " << deletedCount << " duplicate images." << std::endl;
        return deletedCount;
    }
};

class AccountImageManager {
public:
    static std::string SetImageAsAccountPicture(const Image& image, const Account& account) {
        return "Account picture set for user: " + account.getUsername();
    }
};

class ImageResizer {
public:
    static std::string Resize(const Image& image, int height, int width) {
        return "Image resized to " + std::to_string(width) + "x" + std::to_string(height) + ": " + image.getFilename();
    }
};

class ImageDownloader {
public:
    static std::string Download(const Url& imageUrl) {
        return "Image downloaded from URL: " + imageUrl.getUrl();
    }
};

int main() {
    Image image("example.jpg"); 
    Account account("user123"); 
    Url url("http://example.com/image.jpg"); 

    std::cout << ImageSaver::Save(image) << std::endl;

    DuplicateRemover::DeleteDuplicates();

    std::cout << AccountImageManager::SetImageAsAccountPicture(image, account) << std::endl;

    std::cout << ImageResizer::Resize(image, 100, 100) << std::endl;

    std::cout << ImageDownloader::Download(url) << std::endl;

    return 0;
}
