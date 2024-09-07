install.packages("shiny")
install.packages("ggplot2")
install.packages("magrittr")
library(shiny)
library(ggplot2)
library(magrittr)

ui <- fluidPage(
  titlePanel("21BDS0340"),
  sidebarLayout(
    sidebarPanel(
      sliderInput("num_points", "Number of Points:", min = 10, max = 100, value = 50),
      actionButton("generate", "Generate Plot")
    ),
    mainPanel(
      plotOutput("scatterPlot")
    )
  )
)

server <- function(input, output) {
  generate_data <- function(num_points) {
    data.frame(
      x = rnorm(num_points),
      y = rnorm(num_points)
    )
  }
  
  output$scatterPlot <- renderPlot({
    generate_data(input$num_points) %>%
      ggplot(aes(x = x, y = y)) +
      geom_point() +
      labs(title = "Random Scatter Plot", x = "X axis", y = "Y axis")
  })

  observeEvent(input$generate, {
    output$scatterPlot <- renderPlot({
      generate_data(input$num_points) %>%
        ggplot(aes(x = x, y = y)) +
        geom_point() +
        labs(title = "Random Scatter Plot", x = "X axis", y = "Y axis")
    })
  })
}

shinyApp(ui = ui, server = server)
