#ifndef CPP_POINTARRAY_H
#define CPP_POINTARRAY_H

#include "Point.h"

namespace taskPoint {

    /// Коллекция объектов Point в виде массива.
    class PointArray {

    public:
        typedef unsigned int Uint;

    public:
        /** \brief Конструктор по умолчанию.
         *
         *  Создает массив размером 0.
         */
        PointArray();

        /** \brief Конструктор инициализации c-style массивом.
         *
         *  Конструктор инициализирует объект заданным c-style массивом точек и его размером n.
         *  \param[in] points C-style массив точек.
         *  \param[in] n Размер входного массива точек.
         */
        PointArray(const Point points[], const Uint n);

        /** \brief Конструктор инициализации массивом PointArray.
         *
         *  Выполняет копирование массива.
         *  \param[in] other Массив, который будет скопирован.
         */
        PointArray(const PointArray& other);

        /** \brief Конструктор инициализации массивом PointArray.
         *
         *  Выполняет перемещение массива.
         *  \param other Массив, который будет перемещен.
         */
        PointArray(PointArray&& other) noexcept;

        /// Деструктор, который освобождает выделенную память (удаляет внутренний массив).
        ~PointArray();

        /** \brief Оператор присваивания копированием.
         *
         *  Выполняет копирование другого объекта PointArray в данный.
         */
        PointArray& operator=(const PointArray& other);

        /** \brief Оператор присваивания перемещением.
         *
         *  Выполняет перемещение другого объекта PointArray в данный.
         */
        PointArray& operator=(PointArray&& other) noexcept;

        /// Добавляет Point \c pt в конец массива.
        void append(const Point& pt);

        /** \brief Удаляет Point в заданной позиции массива, сдвигая элементы после позиции влево.
         *
         * \param[in] pos — индекс элемента для удаления.
         * Если \c pos больше, чем количество элементов, то ничего не делает.
         * Если удаленный элемент является последним, то базовый массив очищается.
         */
        void remove(Uint pos);

        /** \brief Вставляет Point в заданную позицию массива, сдвигая элементы начиная с позиции вправо.
         *
         *  \param[in] pos — индекс элемента для вставки.
         *  Если \c pos == 0, вставляет точку в начало массива.
         *  Если \c pos больше количества элементов, вставляет точку в конец массива.
         */
        void insert(const Point& pt, const Uint pos);

        /// Удаляет все элементы массива и устанавливает его размер равным 0.
        void clear();

        /// Возвращает размер массива.
        Uint getSize() const;

        /** \brief Оператор индексирования.
         *
         * Выполняет обращение к элементу массива.
         * Элемент возвращается по ссылке, может находиться как в позиции \a rhv, так и в позиции \a lhv.
         * \param[in] index — индекс элемента. Если указанный индекс находится вне диапазона массива,
         * генерируется исключение \c std::out_of_range.
         * \return Возвращает ссылку на \a index элемент массива.
         */
        Point& operator[](const Uint index);

        /** \brief Константная перегруженная версия метода Point::operator[].
         *
         *  Возвращает константную ссылку на элемент, которая может находиться только в позиции \a rhv.
         */
        const Point& operator[](const Uint index) const;

        /** \brief Меняет размер исходного массива.
         *
         * Выделяет новый массив размера \a n, копирует в него первые
         * min(предыдущий размер массива, n) существующих элементов и освобождает старый массив.
         * \param[in] n — новый размер массива.
         */
        void resize(const Uint n);


        /// Возвращает указатель на базовый массив. Может быть использован только в позиции \a rhv.
        const Point* getRawPtr() const { return arr_; };

    protected:
        /// Текущий размер массива.
        Uint size_;
        /// Текущая вместимость
        Uint capacity_;
        /// Указатель на c-style массив.
        Point* arr_;
    };

}

#endif //CPP_POINTARRAY_H